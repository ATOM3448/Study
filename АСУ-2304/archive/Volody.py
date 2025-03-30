from os import name
from tkinter import FIRST
import pandas as pd
import numpy as np
import csv

#ЗАЛИЛ СЫРУЮ ВЕРСИЮ

# Считываем файл
data = pd.read_csv('data.csv')
ocenka_students = pd.read_csv('ocenka-students.csv')

# Создаем 2 нужные таблицы
data = data[['connection_id', 'semester', 'discipline_name']]
ocenka_students = ocenka_students.drop(columns=['enrollment_at', 'deleted_at', 'id'], axis=1).rename(columns={'study_id':'connection_id'})


# проводим слияние по ключу connection_id
stud_group = pd.merge(data, ocenka_students, on='connection_id')


# print(stud_group)


# Информация по группам
# 1 направление: Программное обеспечение средств вычислительной техники и автоматизированных систем

# 1 УП: 435-3 / 435-1
# 1 id: 18 / 93

# 2 УП: 437-1 / 437-2
# 2 id: 413 / 414

# 3 УП: 438-1 / 438-2 / 438-3
# 3 id: 472 / 477 / 482(+)


# 2 направление: Системы автоматизированного проектирования
# 1 УП: 584-1 / 584-2 
# 1 id: 157 / 188 

# 2 УП: 585-2 / 585-1
# 2 id: 28 / 136

# 3 УП: 586-2
# 3 id: 127

# 4 УП: 587-1 / 587-3
# 4 id: 363 / 374

# 4 УП: 588-1 / 588-2 / 588-3
# 4 id: 478 / 483 / 488


# 3 направление: Автоматизированное управление бизнес-процессами и финансами

# 1 УП: 547
# 1 id: 541

# 2 УП: 548-1 / 548-2
# 2 id: 469(+) / 473(-)

# группы по которым есть данные (1)1 482 (3)2 469, 3 473(-)
# 157091, 157383, 157395
# print(stud_group.loc[ (stud_group['group_id'] == 473) & (stud_group['semester'] == 4) ]) 

# Корреляция !!!

cor1_col = stud_group.loc[stud_group['connection_id'] == 157091]
cor1_col = cor1_col[['discipline_name']]
print(cor1_col)
"""buf1 = np.array((47,47))
for i in range(47):
    for j in range(47):
        if i == j:
            buf1[i][j] = 3
 print(buf1)"""

cor1 = pd.DataFrame(columns=cor1_col,index=cor1_col)




cor2_col = stud_group.loc[stud_group['connection_id'] == 157383]
cor2_col = cor2_col[['discipline_name']]

cor2 = pd.DataFrame(columns=cor2_col,index=cor2_col)
# print(cor2)
