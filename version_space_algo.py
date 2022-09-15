def f(x):#Target function
    return 6*x[0]+5*x[1]+(10*x[2]);
Hypothesis=[]
VersionSPACE=[]
Hypothesis.append([1,2,3])
Hypothesis.append([2,36,46])
Hypothesis.append([2,14,6])
Hypothesis.append([5,34,67])
Hypothesis.append([3,3,6])
Hypothesis.append([2,45,6])
Hypothesis.append([23,23,1])
Hypothesis.append([0,0,0])
VersionSPACE.append(Hypothesis)
size=len(VersionSPACE[0])
for i in range(size):
    if(f(VersionSPACE[0][size-i-1])):
        VersionSPACE[0].remove(VersionSPACE[0][size-i-1])
    else:
        continue
print(VersionSPACE[0])
#print(f(VersionSPACE[0][0]))
#print(Hypothesis)
#print(type(Hypothesis[0][0]))
