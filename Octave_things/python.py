import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import pandas as pd
import seaborn as sb

titanic = pd.read_csv('titanic.csv')
print(titanic.shape)
titanic['Relatives'] = titanic.SibSp + titanic.Parch
#titanic.assign(relativ=(titanic.SibSp + titanic.Parch)>0)
# male1 = titanic.query("Sex == 'male' and Survived == 1").Sex.count()
# male0 = titanic.query("Sex == 'male' and Survived == 0").Sex.count()
# women1 = titanic.query("Sex == 'female' and Survived == 1").Sex.count()
# women0 = titanic.query("Sex == 'female' and Survived == 0").Sex.count()
table = pd.pivot_table(titanic[['Survived','Sex']], index=['Sex'], columns=['Survived'], aggfunc=len)
table.plot.pie(subplots=True, figsize=(4,4))
#plt.show()

titanic.loc[titanic.Pclass == 1, 'Pclass'] = 'буржуи'
titanic.loc[titanic.Pclass == 2, 'Pclass'] = 'средний класс'
titanic.loc[titanic.Pclass == 3, 'Pclass'] = 'пролетариат'
lab = 'буржуи', 'средний класс', 'пролетариат'
sizes=[titanic.loc[titanic.Pclass == 'буржуи', 'Pclass'].count(),
        titanic.loc[titanic.Pclass == 'средний класс', 'Pclass'].count(),
        titanic.loc[titanic.Pclass == 'пролетариат', 'Pclass'].count()]
# Pclass bar chart
fig = plt.figure(figsize=(6, 4))
ax1 = fig.add_subplot()
ax1.bar(lab,sizes)
# before and after number of people bar chart
fig = plt.figure()
ax1 = fig.add_subplot()
ax1.bar(['Before', 'After'], [titanic.shape[0], titanic.loc[titanic.Survived == 1].PassengerId.count()])
# add new column about decision of price
titanic['High_price'] = titanic.Fare.apply(lambda x: 'cheap' if x < 25 else 'expensive')
# make histogram
titanic.hist()
plt.show()