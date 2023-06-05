import matplotlib.pyplot
import numpy as np
import matplotlib as mpl
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import axes3d
import pandas as pd
import seaborn as sb

df = pd.read_excel('Data_exam.xlsx')
df = df.rename(columns={'Unnamed: 0':'ID', 'Unnamed: 2':'Onk', 'Unnamed: 4':'Sex',
                   'Unnamed: 6':'Age', 'Unnamed: 9':'Avercm', 'Unnamed: 24':'Smoke',
                   'Unnamed: 21':'StructHearth','Unnamed: 30':'SuvLung', 'Unnamed: 31':'SuvBlood',
                        'Unnamed: 15':'Location', 'Unnamed: 17':'Cont', 'Unnamed: 19':'Type',
                        'Unnamed: 23':'Comorbid'})
df = df.drop([0])
# --------------------------distribution main units--------------------------------------------------
# primarily age is 60, exist dependency from age: 58-75 but records with this age are significant number
# av0 = df.Age.values
# un_av0 = np.unique(av0)
# fig1, ax = plt.subplots()
# ax.bar(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# ax.set_title('Age distribution')
# ax.set_xlabel('Age')
# ax.set_ylabel('Number')

# major frequent size Onk/NotOnk is about 28mm
# av0 = df.Avercm.values
# un_av0 = np.unique(av0)
# fig1, ax = plt.subplots()
# ax.bar(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# ax.set_title('Average size distribution')
# ax.set_xlabel('Size')
# ax.set_ylabel('Number of people')

# SuvLung
# av0 = df.SuvLung.values
# un_av0 = np.unique(av0)
# fig1, ax = plt.subplots()
# ax.bar(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# ax.set_title('SUV hearth/lung distribution in general')
# ax.set_xlabel('Volume')
# ax.set_ylabel('Frequent')

# SUV hearth/blood pool
# av0 = df.SuvBlood.values
# un_av0 = np.unique(av0)
# fig1, ax = plt.subplots()
# ax.bar(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# ax.set_title('SUV hearth/blood pool distribution in general')
# ax.set_xlabel('Volume')
# ax.set_ylabel('Frequent')

# ----------------------------Feature analysis------------------------------------------
# people who have onk in age 76+ achieved 75%
# print(df.query("Onk == 1 and Age >= 76").ID.count()/
#       df.query("Age >= 76").ID.count())
# people who have onk in age 55-75 achieved 62%
# print(df.query("Onk == 1 and Age >= 55 and Age <= 75").ID.count()/
#       df.query("Age >= 55 and Age <= 75").ID.count())
# people who have onk in age 35-55 achieved 37%
# print(df.query("Onk == 1 and Age >= 35 and Age < 55").ID.count()/
#       df.query("Age >= 35 and Age < 55").ID.count())
# people who have onk in age 20-35 achieved 13%
# print(df.query("Onk == 1 and Age >= 20 and Age < 35").ID.count()/
#       df.query("Age >= 20 and Age < 35").ID.count())
# fig = plt.figure()
# ax1 = fig.add_subplot()
# ax1.bar(['20-34', '35-54', '55-74', '75+'],
#         [df.query("Onk == 1 and Age >= 20 and Age < 35").ID.count()/
#             df.query("Age >= 20 and Age < 35").ID.count()*100,
#          df.query("Onk == 1 and Age >= 35 and Age < 55").ID.count()/
#             df.query("Age >= 35 and Age < 55").ID.count()*100,
#          df.query("Onk == 1 and Age >= 55 and Age <= 75").ID.count() /
#             df.query("Age >= 55 and Age <= 75").ID.count()*100,
#          df.query("Onk == 1 and Age >= 76").ID.count() /
#             df.query("Age >= 76").ID.count()*100])
# ax1.set_ylabel('Percentage')
# ax1.set_xlabel('Age')
# ax1.set_title('with oncology out of the total')

# there isn't explicit dependency between onk and size
# av0 = df.loc[df.Onk == 0].Avercm.values
# av1 = df.loc[df.Onk == 1].Avercm.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _,el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _,el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Average size with/without oncology')
# ax.set_xlabel('Size (mm)')
# ax.set_ylabel('Frequent')

# Onk and SuvLung
# av0 = df.loc[df.Onk == 0].SuvLung.values
# av1 = df.loc[df.Onk == 1].SuvLung.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, (ax, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(9,4))
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax2.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.set_title('SUV hearth/lung without oncology')
# ax.set_ylim([0,14])
# ax2.set_ylim([0,14])
# ax.set_xlim([0,60])
# ax2.set_xlim([0,60])
# ax2.set_title('SUV hearth/lung with oncology')
# ax.set_xlabel('Volume')
# ax.set_ylabel('Frequent')
# ax2.set_xlabel('Volume')
# ax2.set_ylabel('Frequent')

# comparison Onk and SuvBlood
# av0 = df.loc[df.Onk == 0].SuvBlood.values
# av1 = df.loc[df.Onk == 1].SuvBlood.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, (ax, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(9,4))
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax2.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.set_title('SUV hearth/blood pool without oncology')
# ax.set_ylim([0,14])
# ax.set_xlim([0,25])
# ax2.set_xlim([0,25])
# ax2.set_ylim([0,14])
# ax2.set_title('SUV hearth/blood pool with oncology')
# ax.set_xlabel('Volume')
# ax.set_ylabel('Frequent')
# ax2.set_xlabel('Volume')
# ax2.set_ylabel('Frequent')

# comparison onk and age. The most frequent age with onk is 59
# Onk and Age and Sex
# fig1, (ax, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(9,4))
# x = np.array([i for i in range(20, 71, 10)])
# y1 = [df.query(f"Onk == 1 and Sex == 'м' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# y2 = [df.query(f"Onk == 1 and Sex == 'ж' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# line1 = ax.bar(x - 1.5, y1, width=3)
# line2 = ax.bar(x + 1.5, y2, width=3)
# ax.set_xlabel('Age')
# ax.set_ylabel('Number of people')
# ax.legend((line1, line2), ['Men', 'Women'], loc='upper left')
# ax.set_title('Gender/with cancer')
# y1 = [df.query(f"Onk == 0 and Sex == 'м' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# y2 = [df.query(f"Onk == 0 and Sex == 'ж' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# line1 = ax2.bar(x - 1.5, y1, width=3)
# line2 = ax2.bar(x + 1.5, y2, width=3)
# ax2.set_xlabel('Age')
# ax2.set_ylabel('Number of people')
# ax2.legend((line1, line2), ['Men', 'Women'], loc='upper left')
# ax2.set_title('Gender/without cancer')

# onk and men 10/ women 10 in 59 age, age is 55+ 120m(67% in all) 98w(59% in all),
#print(df.query("Age == 59 and Sex == 'м' and Onk == 1").ID.count())
#print(df.query("Age == 59 and Sex == 'ж' and Onk == 1").ID.count())
#print(df.query("Age >= 55 and Sex == 'м' and Onk == 1").ID.count())
#print(df.query("Age >= 55 and Sex == 'ж' and Onk == 1").ID.count())
# print(df.query("Age >= 55 and Sex == 'м' and Onk == 1").ID.count()/
#       df.query("Age >= 55 and Sex == 'м'").ID.count())
# print(df.query("Age >= 55 and Sex == 'ж' and Onk == 1").ID.count()/
#       df.query("Age >= 55 and Sex == 'ж'").ID.count())

# Onk and Sex, 142 (56% in all) men and 121 (52% in all) women with onk.
# Sex doesn't matter for onk
# fig, (ax1, ax2) = plt.subplots(nrows=1,ncols=2,figsize=(8,4))
# ax1.pie([df.query("Sex == 'м' and Onk == 1").ID.count(),
#          df.query("Sex == 'м' and Onk == 0").ID.count()],
#         labels=['Oncology', 'Normal'], autopct='%.1f', explode=[0.1,0], shadow=True)
# ax1.set_title('Men')
# ax2.pie([df.query("Sex == 'ж' and Onk == 1").ID.count(),
#          df.query("Sex == 'ж' and Onk == 0").ID.count()],
#         labels=['Oncology', 'Normal'], autopct='%.1f',explode=[0.1,0], shadow=True)
# ax2.set_title('Women')

# Onk and Smoke. Smoking have influence on oncology but this impact isn't significant
# fig, (ax1, ax2) = plt.subplots(nrows=1,ncols=2,figsize=(8,4))
# ax1.pie([df.query("Smoke == 'да' and Onk == 1").ID.count(),
#          df.query("Smoke == 'да' and Onk == 0").ID.count()],
#         labels=['Oncology', 'Normal'], autopct='%.1f', explode=[0.1,0], shadow=True)
# ax1.set_title('Smoker')
# ax2.pie([df.query("Smoke == 'нет' and Onk == 1").ID.count(),
#          df.query("Smoke == 'нет' and Onk == 0").ID.count()],
#         labels=['Oncology', 'Normal'], autopct='%.1f',explode=[0.1,0], shadow=True)
# ax2.set_title('Non-smoker')

# Onk and struct of hearth. There isn't influence on oncology.
# av0 = df.loc[df.Onk == 0].StructHearth.values
# av1 = df.loc[df.Onk == 1].StructHearth.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Onk and struct of hearth')
# ax.set_xlabel('Type')
# ax.set_ylabel('Frequent')

# Onk and location of hearth. There isn't influence on oncology.
# av0 = df.loc[df.Onk == 0].Location.values
# av1 = df.loc[df.Onk == 1].Location.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Onk and location of hearth')
# ax.set_xlabel('Type')
# ax.set_ylabel('Frequent')

# Onk and contour of hearth. If contour has 2nd type, there is a big frequent that it's oncology (not 100%)
# av0 = df.loc[df.Onk == 0].Cont.values
# av1 = df.loc[df.Onk == 1].Cont.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Onk and contour of hearth')
# ax.set_xlabel('Type')
# ax.set_ylabel('Frequent')

# Onk and type of hearth. There isn't influence on oncology. 1 record has 3d type of hearth.
# av0 = df.loc[df.Onk == 0].Type.values
# av1 = df.loc[df.Onk == 1].Type.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Onk and type of hearth')
# ax.set_xlabel('Type')
# ax.set_ylabel('Frequent')

# Onk and comorbid pathology. If it's 1st or 3d comorbid pathology, that isn't oncology with big frequent
# av0 = df.loc[df.Onk == 0].Comorbid.values
# av1 = df.loc[df.Onk == 1].Comorbid.values
# un_av0 = np.unique(av0)
# un_av1 = np.unique(av1)
# fig1, ax = plt.subplots()
# line1, = ax.plot(un_av0, [np.count_nonzero(av0 == el) for _, el in enumerate(un_av0)])
# line2, = ax.plot(un_av1, [np.count_nonzero(av1 == el) for _, el in enumerate(un_av1)])
# ax.legend((line1, line2), ['normal', 'oncology'])
# ax.set_title('Onk and comorbid pathotology')
# ax.set_xlabel('Type')
# ax.set_ylabel('Frequent')

# Onk and Age and Smoking. There isn't difference between smoker and non-smoker with/without oncology
# fig1, (ax, ax2) = plt.subplots(nrows=1, ncols=2, figsize=(9,4))
# x = np.array([i for i in range(20, 71, 10)])
# y1 = [df.query(f"Onk == 1 and Smoke == 'да' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# y2 = [df.query(f"Onk == 1 and Smoke == 'нет' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# line1 = ax.bar(x - 1.5, y1, width=3)
# line2 = ax.bar(x + 1.5, y2, width=3)
# ax.legend((line1, line2), ['Smoker', 'Non-smoker'], loc='upper left')
# ax.set_title('Smoking and age with oncology')
# ax.set_xlabel('Age')
# ax.set_ylabel('Number of people')
#
# x = np.array([i for i in range(20, 71, 10)])
# y1 = [df.query(f"Onk == 0 and Smoke == 'да' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# y2 = [df.query(f"Onk == 0 and Smoke == 'нет' and Age >= {el} and Age < {el+10}").ID.count() for _, el in enumerate(x)]
# line1 = ax2.bar(x - 1.5, y1, width=3)
# line2 = ax2.bar(x + 1.5, y2, width=3)
# ax2.legend((line1, line2), ['Smoker', 'Non-smoker'], loc='upper left')
# ax2.set_title('Smoking and age without oncology')
# ax2.set_xlabel('Age')
# ax2.set_ylabel('Number of people')

# Onk and Age and SuvLung
# sb.lmplot(data=df, x='Age', y='SuvLung', hue='Onk', fit_reg=False)

# Onk and SuvLung and SuvBlood
# sb.lmplot(data=df, x='SuvLung', y='SuvBlood', hue='Onk', fit_reg=False)

# Onk and Cont and SuvBlood
# sb.lmplot(data=df, x='Cont', y='SuvBlood', hue='Onk', fit_reg=False)
# plt.show()