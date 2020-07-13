pr=[]
r=open("input.txt")
line_n=-1
for line in r:
    pr.append([])
    line_n+=1
    line=line[3:-2:]
    temp=""
    x=-1
    while x<len(line)-1:
        x+=1
        if line[x]=="{":
            counter=1
            temp+=line[x]
            for j in range(x+1,len(line)):
                if line[j]=="{":
                    counter+=1
                elif line[j]=="}":
                    counter-=1
                temp+=line[j]
                if counter==0:
                    x=j+1 
                    break
        elif line[x]==",":
            pr[line_n].append(temp)
            temp=""
                    
        else:
            temp+=line[x]
    else:
        pr[line_n].append(temp)
for x in range(len(pr)):
    print(pr[x])
result=[]

def rec(st,a):
    if len(a)==2:
        for i in range(len(a[0])):
            for j in range(len(a[1])):
                result.append(st+","+str(a[0][i])+","+str(a[1][j]))
        return
    for i in range(len(a[0])):
        rec(st+","+str(a[0][i]),a[1::])
    
for i in range(len(pr[0])):
    rec(str(pr[0][i]),pr[1::])
print("\nЭлементы множества:\n")
for i in range(len(result)):
    print("<"+result[i]+">")
