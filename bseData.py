from ast import If
from sklearn.impute import SimpleImputer
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import seaborn as sns
df = pd.read_csv("22april2022.csv", delimiter=',')
#salary = np.array(df['salary'])
# print(df)
# print(df.isna().any())
# print(df.header())
# for i in df:
#     print(i)
call_bid_price = np.array(df["BID PRICE"])
call_volume = np.array(df["VOLUME"])
# print(call_bid_price)
# print(call_volume)
size = call_volume.size
#print(size)
call_amount = 0.0
for i in range(0, size):
    if call_volume[i] == '-':
        call_volume[i] = 0
print(type(call_volume[0]))
call_amount=float(call_volume[0])
# for i in range(0, size):
#     call_amount += int(call_volume[i])*float(call_bid_price[i])
print(call_amount)
