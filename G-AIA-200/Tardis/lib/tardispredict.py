import pandas as pd
import numpy as np
from typing import Any

FEATURES: list[str] = [
    "Average journey time",
    "Number of scheduled trains",
    "Number of cancelled trains",
    "Number of trains delayed > 15min",
    "Number of trains delayed > 30min",
    "Number of trains delayed > 60min",
    "Mois",
    "Jour de la semaine",
]

CLEAN_FEATURES: list[str] = [
    "Average journey time",
    "Number of scheduled trains",
    "Number of cancelled trains",
    "Number of trains delayed > 15min",
    "Number of trains delayed > 30min",
    "Number of trains delayed > 60min",
    "Mois",
    "Jour de la semaine",
]

SUPPL_FEATURES_ARRS: list[str] = [
    "Number of trains delayed at arrival",
    "Average delay of late trains at arrival",
    "Average delay of all trains at arrival",
]

SUPPL_CLEAN_FEATURES_ARRS: list[str] = [
    "Number of trains delayed at arrival",
    "Average delay of late trains at arrival",
    "Average delay of all trains at arrival",
]

SUPPL_FEATURES_DEPS: list[str] = [
    "Number of trains delayed at departure",
    "Average delay of late trains at departure",
    "Average delay of all trains at departure",
]

SUPPL_CLEAN_FEATURES_DEPS: list[str] = [
    "Number of trains delayed at departure",
    "Average delay of late trains at departure",
    "Average delay of all trains at departure",
]

DAYS = ["Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"]


## Tuple 0 : Month
## Tuple 1 : Day
def predict_lateness(
    lang_pack: dict, date: tuple[str, str], element: pd.DataFrame, model: Any
):
    element["Jour de la semaine"] = element["Jour de la semaine"]

    if date is not None:
        day_index: int = list(lang_pack["generic"]["dates"]).index(date[1])
        element = element.loc[element["Mois"] == date[0]]
        element = element.loc[element["Jour de la semaine"] == DAYS[day_index]]

    element["Jour de la semaine"] = (
        element["Jour de la semaine"].astype("category").cat.codes
    )

    element = element[FEATURES]

    prediction = model.predict(element.values)
    return float(np.mean(prediction))


## Tuple 0 : Month
## Tuple 1 : Day
def predict_lateness_deps(
    lang_pack: dict, date: tuple[str, str], element: pd.DataFrame, model: Any
):
    element["Jour de la semaine"] = element["Jour de la semaine"]

    if date is not None:
        day_index: int = list(lang_pack["generic"]["dates"]).index(date[1])
        element = element.loc[element["Mois"] == date[0]]
        element = element.loc[element["Jour de la semaine"] == DAYS[day_index]]

    element["Jour de la semaine"] = (
        element["Jour de la semaine"].astype("category").cat.codes
    )

    element = element[FEATURES + SUPPL_FEATURES_DEPS]

    prediction = model.predict(element.values)
    return float(np.mean(prediction))


## Tuple 0 : Month
## Tuple 1 : Day
def predict_lateness_arrs(
    lang_pack: dict, date: tuple[str, str], element: pd.DataFrame, model: Any
):
    element["Jour de la semaine"] = element["Jour de la semaine"]

    if date is not None:
        day_index: int = list(lang_pack["generic"]["dates"]).index(date[1])
        element = element.loc[element["Mois"] == date[0]]
        element = element.loc[element["Jour de la semaine"] == DAYS[day_index]]

    element["Jour de la semaine"] = (
        element["Jour de la semaine"].astype("category").cat.codes
    )

    element = element[FEATURES + SUPPL_FEATURES_ARRS]

    prediction = model.predict(element.values)
    return float(np.mean(prediction))
