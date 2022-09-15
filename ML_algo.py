'''
from prettytable import PrettyTable
table=PrettyTable("All column names")
table.add_rows(List)
or 
table.add_row(List[i])
print(table)
'''
List=[]
Hypothesis=[["NULL","NULL","NULL","NULL","NULL"]]
List.append(["Country","Company","Established","Performance","Usefulness"])
List.append(["Japan","Honda","1970","Good","-ve"])
List.append(["India","Tata","1870","Excellent","+ve"])
List.append(["India","Birla","1870","Average","+ve"])
List.append(["India","Fevicol","1870","Fair","+ve"])
List.append(["India","Maruti","1870","Excellent","+ve"])
List.append(["India","Jayprakash power ventures","1870","Excellent","+ve"])

#List.remove(List[0])
#to remove the ith element from the list
#Hypothesis.append(List[0])
flag=0
for i in range(1,len(List)):
        if(List[i][4]=="-ve"):
                continue
        elif(List[i][4]=="+ve" and flag==0):
                Hypothesis.remove(Hypothesis[0])
                Hypothesis.append(List[i])
                flag=1
                
        else:
                for j in range(0,len(List[i])-1):
                        if(Hypothesis[0][j]==List[i][j]):
                                continue
                        else:
                                Hypothesis[0][j]="?"
                        
        #else:
         #       Hypothesis.clear()#this is to delete the whole list
          #      Hypothesis.append(List[i])
for i in range(len(List)):
    for j in range(len(List[i])):
        print(List[i][j],end=" \t")
    print("")
print("\n\n\nThis is the most general hypothesis solution\n\n\n\n\n\n")
print(Hypothesis) # this is the most general hypothesis solution
#print("{<8} {<9} {<8}".format())

