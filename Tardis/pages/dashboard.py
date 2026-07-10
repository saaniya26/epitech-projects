import streamlit as st
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns
import joblib
import lib.tardispredict as tardispredict


class Window:
    def __init__(self):
        self.df = None
        self.model = None
        self.model_deps = None
        self.model_arrs = None
        self.start_proc_df = None
        self.finish_proc_df = None
        self.lang_dict = st.session_state["language_dict"]

        try:
            self.df = pd.read_csv("cleaned_dataset.csv")
        except Exception as e:
            st.warning(f"{self.lang_dict['pages']['panel']['dataset-fail']}\n{e}")

        try:
            self.model = joblib.load("tardis_rf_model.joblib")
        except Exception as e:
            st.warning(f"{self.lang_dict['pages']['panel']['model-fail']}.\n{e}")

        try:
            self.model_deps = joblib.load("tardis_rf_model_departures.joblib")
        except Exception as e:
            st.warning(f"{self.lang_dict['pages']['panel']['model-fail']}.\n{e}")

        try:
            self.model_arrs = joblib.load("tardis_rf_model_arrivals.joblib")
        except Exception as e:
            st.warning(f"{self.lang_dict['pages']['panel']['model-fail']}.\n{e}")

        st.title(self.lang_dict["pages"]["panel"]["title"])

        lateness_line_container = st.container()
        lateness_graphs_container = st.container()
        with lateness_line_container:
            self.lateness_line()
        st.divider()
        with lateness_graphs_container:
            self.lateness_graphs()

    def lateness_line(self):
        def lateness_prediction_manual_start():
            station = st.selectbox(
                self.lang_dict["pages"]["panel"]["man-pred:start-station"],
                self.df["Departure station"].dropna().unique(),
                key="start1",
            )

            df_station: pd.DataFrame = self.df[self.df["Departure station"] == station]

            df_station.dropna(
                subset=tardispredict.CLEAN_FEATURES
                + tardispredict.SUPPL_CLEAN_FEATURES_DEPS
            )

            st.write(
                f"{self.lang_dict['pages']['panel']['man-pred:n-travels']}: ",
                df_station.shape[0],
            )

            st.subheader(self.lang_dict["pages"]["panel"]["man-pred:start-subtitle"])
            fig, ax = plt.subplots()
            sns.histplot(
                df_station["Average delay of all trains at departure"].dropna(),
                bins=30,
                ax=ax,
            )
            st.pyplot(fig)

            try:
                if self.model is None:
                    raise Exception("Model isn't loaded.")
                mois = st.selectbox(
                    self.lang_dict["pages"]["panel"]["man-pred:month"],
                    sorted(df_station["Mois"].dropna().unique())
                    if "Mois" in df_station
                    else list(range(1, 13)),
                    key="start5",
                )
                jour_semaine_map = {
                    name: code
                    for code, name in enumerate(self.lang_dict["generic"]["dates"])
                }
                jour_semaine = st.selectbox(
                    self.lang_dict["pages"]["panel"]["man-pred:weekday"],
                    list(jour_semaine_map.keys()),
                    key="start6",
                )
                if len(df_station.index) <= 0:
                    raise Exception("No data in element")

                if st.button(
                    self.lang_dict["pages"]["panel"]["man-pred:predict"], key="start7"
                ):
                    prediction = tardispredict.predict_lateness_deps(
                        self.lang_dict,
                        (mois, jour_semaine),
                        df_station.copy(),
                        self.model_deps,
                    )
                    st.info(
                        f"{self.lang_dict['pages']['panel']['man-pred:pred-success']}: {prediction:.2f}m"
                    )
            except ValueError:
                st.error(
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail']}:  \n" +\
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail-nodat']}"
                )
            except Exception as e:
                st.error(
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail']}: {e}"
                )

        def lateness_prediction_manual_finish():
            station = st.selectbox(
                self.lang_dict["pages"]["panel"]["man-pred:end-station"],
                self.df["Arrival station"].dropna().unique(),
                key="finish1",
            )

            df_station: pd.DataFrame = self.df[self.df["Arrival station"] == station]

            df_station.dropna(
                subset=tardispredict.CLEAN_FEATURES
                + tardispredict.SUPPL_CLEAN_FEATURES_ARRS
            )

            st.write(
                f"{self.lang_dict['pages']['panel']['man-pred:n-travels']}: ",
                df_station.shape[0],
            )

            st.subheader(self.lang_dict["pages"]["panel"]["man-pred:end-subtitle"])
            fig, ax = plt.subplots()
            sns.histplot(
                df_station["Average delay of all trains at arrival"].dropna(),
                bins=30,
                ax=ax,
                color="green"
            )
            st.pyplot(fig)

            try:
                if self.model is None:
                    raise Exception("Model isn't loaded.")
                mois = st.selectbox(
                    self.lang_dict["pages"]["panel"]["man-pred:month"],
                    sorted(df_station["Mois"].dropna().unique())
                    if "Mois" in df_station
                    else list(range(1, 13)),
                    key="finish5",
                )
                jour_semaine_map = {
                    name: code
                    for code, name in enumerate(self.lang_dict["generic"]["dates"])
                }
                jour_semaine = st.selectbox(
                    self.lang_dict["pages"]["panel"]["man-pred:weekday"],
                    list(jour_semaine_map.keys()),
                    key="finish6",
                )
                if len(df_station.index) <= 0:
                    raise Exception("No data in element")

                if st.button(
                    self.lang_dict["pages"]["panel"]["man-pred:predict"], key="finish7"
                ):
                    prediction = tardispredict.predict_lateness_arrs(
                        self.lang_dict,
                        (mois, jour_semaine),
                        df_station.copy(),
                        self.model_arrs,
                    )
                    st.info(
                        f"{self.lang_dict['pages']['panel']['man-pred:pred-success']}: {prediction:.2f}m"
                    )
            except ValueError:
                st.error(
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail']}:  \n" +\
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail-nodat']}"
                )
            except Exception as e:
                st.error(
                    f"{self.lang_dict['pages']['panel']['man-pred:pred-fail']}: {e}"
                )

        def lateness_prediction_list_start(mois, jour_semaine):
            prediction_table = {"Station": [], "Retard en moyenne (min)": []}

            st.subheader(self.lang_dict["pages"]["panel"]["auto-pred:subtitle-start"])

            progress_text: str = f"??.??% - S: ?? | E: ?? | T: ??  \n{self.lang_dict['pages']['panel']['auto-pred:analysis']} '<UNKNOWN>'..."
            progress_bar = st.progress(0, text=progress_text)
            prog_success = 0
            prog_fail = 0

            departure_stations = self.df["Departure station"].dropna().unique()

            data_size: int = len(departure_stations)

            for i in range(data_size):
                try:
                    element: pd.DataFrame = self.df[
                        self.df["Departure station"] == departure_stations[i]
                    ]
                    element.dropna(
                        subset=tardispredict.CLEAN_FEATURES
                        + tardispredict.SUPPL_CLEAN_FEATURES_DEPS
                    )
                    if len(element.index) <= 0:
                        raise Exception("No data in element")
                    progress_bar.progress(
                        i / data_size,
                        f"{(i / data_size) * 100:.2f}% - :green-badge[{prog_success}] | :red-badge[{prog_fail}] | :orange-badge[{data_size}]  \n"
                        + f"{self.lang_dict['pages']['panel']['auto-pred:analysis']} :orange-badge[{departure_stations[i]}]...",
                    )
                    prediction = tardispredict.predict_lateness_deps(
                        self.lang_dict,
                        (mois, jour_semaine),
                        element.copy(),
                        self.model_deps,
                    )
                    prediction_table["Station"].append(departure_stations[i])
                    prediction_table["Retard en moyenne (min)"].append(
                        float(round(prediction, 2))
                    )
                    prog_success += 1
                except ValueError:
                    prog_fail += 1
                except Exception as e:
                    print(f"An unknown exception has occured during prediction\n{e}")
                    prog_fail += 1

            progress_bar.progress(
                1.0, self.lang_dict["pages"]["panel"]["auto-pred:pred-end-start"]
            )
            progress_bar.empty()
            st.success(
                f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-start']}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-success']}: {prog_success}/{data_size}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-fail']}: {prog_fail}/{data_size}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-note']}"
            )
            self.start_proc_df = pd.DataFrame(prediction_table)
            with st.expander(self.lang_dict["pages"]["panel"]["auto-pred:raw-data"]):
                st.dataframe(self.start_proc_df, height=200)

        def lateness_prediction_list_finish(mois, jour_semaine):
            prediction_table = {"Station": [], "Retard en moyenne (min)": []}

            st.subheader(self.lang_dict["pages"]["panel"]["auto-pred:subtitle-end"])

            progress_text: str = f"??.??% - S: ?? | E: ?? | T: ??  \n{self.lang_dict['pages']['panel']['auto-pred:analysis']} '<UNKNOWN>'..."
            progress_bar = st.progress(0, text=progress_text)
            prog_success = 0
            prog_fail = 0

            arrival_stations = self.df["Arrival station"].dropna().unique()

            data_size: int = len(arrival_stations)

            for i in range(data_size):
                try:
                    element: pd.DataFrame = self.df[
                        self.df["Arrival station"] == arrival_stations[i]
                    ]
                    element.dropna(
                        subset=tardispredict.CLEAN_FEATURES
                        + tardispredict.SUPPL_CLEAN_FEATURES_ARRS
                    )
                    if len(element.index) <= 0:
                        raise Exception("No data in element")
                    progress_bar.progress(
                        i / data_size,
                        f"{(i / data_size) * 100:.2f}% - :green-badge[{prog_success}] | :red-badge[{prog_fail}] | :orange-badge[{data_size}]  \n"
                        + f"{self.lang_dict['pages']['panel']['auto-pred:analysis']} :orange-badge[{arrival_stations[i]}]...",
                    )
                    prediction = tardispredict.predict_lateness_arrs(
                        self.lang_dict,
                        (mois, jour_semaine),
                        element.copy(),
                        self.model_arrs,
                    )
                    prediction_table["Station"].append(arrival_stations[i])
                    prediction_table["Retard en moyenne (min)"].append(
                        float(round(prediction, 2))
                    )
                    prog_success += 1
                except ValueError:
                    prog_fail += 1
                except Exception as e:
                    print(f"An unknown exception has occured during prediction\n{e}")
                    prog_fail += 1

            progress_bar.progress(
                1.0, self.lang_dict["pages"]["panel"]["auto-pred:raw-data"]
            )
            progress_bar.empty()
            st.success(
                f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-end']}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-success']}: {prog_success}/{data_size}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-fail']}: {prog_fail}/{data_size}  \n"
                + f"{self.lang_dict['pages']['panel']['auto-pred:pred-end-note']}"
            )
            self.finish_proc_df = pd.DataFrame(prediction_table)
            with st.expander(self.lang_dict["pages"]["panel"]["auto-pred:raw-data"]):
                st.dataframe(self.finish_proc_df, height=200)

        # Line Bootup
        late_pred_manual, late_pred_list = st.columns(2)
        with late_pred_manual:
            with st.container(border=True):
                st.header(self.lang_dict["pages"]["panel"]["auto-pred:title"])
                start, finish = st.columns(2)
                with start:
                    lateness_prediction_manual_start()
                with finish:
                    lateness_prediction_manual_finish()
        with late_pred_list:
            st.header(self.lang_dict["pages"]["panel"]["auto-pred:title"])
            mois = st.selectbox(
                self.lang_dict["pages"]["panel"]["man-pred:month"],
                list(range(1, 13)),
                key="departure1",
            )
            jour_semaine_map = {
                name: code
                for code, name in enumerate(self.lang_dict["generic"]["dates"])
            }
            jour_semaine = st.selectbox(
                self.lang_dict["pages"]["panel"]["man-pred:weekday"],
                list(jour_semaine_map.keys()),
                key="departure2",
            )
            lateness_prediction_list_start(mois, jour_semaine)
            st.divider()
            lateness_prediction_list_finish(mois, jour_semaine)

    def lateness_graphs(self):
        st.header(self.lang_dict["pages"]["panel"]["graphs:title"])

        st.subheader(self.lang_dict["pages"]["panel"]["graphs:start"])
        st.bar_chart(
            self.start_proc_df, height=500, x="Station", y="Retard en moyenne (min)"
        )

        st.subheader(self.lang_dict["pages"]["panel"]["graphs:end"])
        st.bar_chart(
            self.finish_proc_df, height=500, x="Station", y="Retard en moyenne (min)"
        )


Window()
