# 🚄 TARDIS - Prédiction des Retards / Lateness Prediction SNCF

Ce projet vise à analyser les données de retards de trains et à prédire les retards futurs grâce au machine learning.

## 📁 Contenu

- `.github/workflows/*` : Workflows nécessaires pour la CI/CD
- `tardis_eda.ipynb` : Analyse exploratoire et nettoyage
- `tardis_model.ipynb` : Entraînement du modèle prédictif
- `tardis_dashboard.py` : Dashboard interactif avec Streamlit
- `pages/*.py` : Pages utilisées par le Dashboard
- `lib/*.py` : Fichiers pythons utilisés par les différents services
- `assets/*` : Données et assets utilisés pour les différents services

## ⚙️ Modules utilisés

- Pandas (``pandas``) : Utilisé pour la manipulation des données (lire le fichier CSV, nettoyer les données, etc.).

- PyPlot (``matplotlib.pyplot``) : Utilisé pour générer des graphiques.

- Seaborn (``seaborn``) : Extension de matplotlib, utilisée pour créer des visualisations statistiques plus avancées et plus esthétiques
  (par exemple, des histogrammes avec courbes de densité).

- Streamlit (``streamlit``) : Utilisé pour facilement faire des dashboard interactifs pour l'IA.

- SkLearn (``sklearn``) : Utilisé pour entrainer des modèles d'IA sous python.

- JobLib (``joblib``) : Utilisé pour extraire et importer des modèles d'IA sous python.

## 📥 Installation des modules

### ✅ En environement Python débloqué

```bash
pip install pandas scikit-learn streamlit matplotlib seaborn
```

### ⛔ En environmenet Python bloqué

#### Avec pip

```bash
pip install pandas scikit-learn streamlit matplotlib seaborn --break-system-packages
```

#### Avec pipx

```bash
sudo apt install pipx
pipx install pandas scikit-learn streamlit matplotlib seaborn
```

## 📊​ Exécution du Dashboard

streamlit run ./tardis_dashboard.py

### ❌ En cas d'erreurs

1. Ajouter le dossier des exécutables python dans le PATH

    ```bash
    echo 'export PATH="$HOME/.local/bin:$PATH"' >> ~/.zshrc
    ```

2. Redemarrez le shell

3. Réessayez la commande
