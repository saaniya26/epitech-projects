import streamlit as st
import json


class MainWindow:
    def __init__(self):
        st.set_page_config(layout="wide")

        self.user = "N/A"
        self.lang = "Français"
        self.lang_defs: dict[str, str] = {
            "Français": "french",
            "English": "english",
        }
        self.lang_dict = None
        self.pages = None

        self.sidebar()

        webpage = st.navigation(self.pages)
        webpage.run()

    def sidebar(self):
        st.sidebar.image("assets/images/sncf_logo.png", width=150)
        st.sidebar.markdown(
            "**TARDIS** - :orange-badge[v1] - :blue-badge[EPITECH 2025]"
        )
        self.lang = st.sidebar.selectbox("Langages", ["Français", "English"])
        with open(f"assets/locales/{self.lang_defs[self.lang]}.json", "r") as file:
            self.lang_dict = json.loads(file.read())
        st.session_state["language_dict"] = self.lang_dict
        self.user = self.lang_dict["sidebar"]["not-authentified"]
        self.pages = {
            self.lang_dict["sidebar"]["home-section"]: [
                st.Page(
                    self.page, title=self.lang_dict["sidebar"]["home-section:homepage"]
                )
            ],
            self.lang_dict["sidebar"]["ctrl-section"]: [
                st.Page(
                    "pages/dashboard.py",
                    title=self.lang_dict["sidebar"]["ctrl-section:panel"],
                )
            ],
        }
        st.sidebar.markdown(
            f"{self.lang_dict['sidebar']['user']}: :red-badge[{self.user}]"
        )

    def page(self):
        st.title(self.lang_dict["pages"]["home"]["title"])


MainWindow()
