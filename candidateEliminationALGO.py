List = []
temp = []
Specific = [["@", "@", "@", "@", "@"]]
General = [["?", "?", "?", "?", "?"]]
List.append(["Country", "Company", "Established", "Performance", "Usefulness"])
List.append(["Japan", "Suzuki", "1978", "Good", "+ve"])
List.append(["Japan", "Honda", "1970", "Good", "-ve"])
List.append(["India", "Tata", "1870", "Excellent", "+ve"])
List.append(["India", "Birla", "1870", "Average", "+ve"])
List.append(["India", "Fevicol", "1870", "Fair", "+ve"])
List.append(["India", "Maruti", "1870", "Excellent", "+ve"])
List.append(["India", "Jayprakash power ventures", "1870", "Excellent", "-ve"])

# List.remove(List[0])
# to remove the ith element from the list
# Hypothesis.append(List[0])
flag = 0
flag2 = 0
gencount = 0
for i in range(1, len(List)):
        if(List[i][4] == "+ve" and flag == 0):
                Specific.remove(Specific[0])
                Specific.append(List[i])
                flag = 1

        elif(List[i][4] == "+ve"):
                for j in range(0, len(List[i])-1):
                        if(Specific[0][j] == List[i][j]):
                                continue
                        else:
                                Specific[0][j] = "?"
        elif(List[i][4] == "-ve"):
                General[0].append([])
                for j in range(0,len(List[i])-1):
                        if(Specific[0][j]==List[i][j]):
                                General[0][gencount].extend(Specific[0][j])
                gencount+=1
            
        # else:
         #       Hypothesis.clear()#this is to delete the whole list
          #      Hypothesis.append(List[i])
for i in range(len(List)):
    for j in range(len(List[i])):
        print(List[i][j],end=" \t")
    print("")
print("\n\n\nThis is the most general hypothesis solution\n\n\n\n\n\n")
print(Specific) # this is the most general hypothesis solution
# print("{<8} {<9} {<8}".format())
print(General[0])
