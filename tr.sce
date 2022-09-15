clc,clear
function[x]=Stirling(x,fx,x1,n)
    y1 = 0,d = 1,temp1 = 1, temp2 = 1,
    k = 1,l=1
    h = x(2) - x(1);
    s = floor(n / 2);
    a = x(s);
    u = (x1 - a) / h;
for i=1:n-1
    delta(i,1) = fx(i + 1) - fx(i);
end
for i=2:n-1 
    for j=1:n-i
        delta(j,i)= delta(j + 1,i - 1)- delta(j,i - 1);
	end
end
// Calculating f(x) using the Stirling
// formula
y1 = fx(s);
for i=2:n
    if (modulo(i-1,2)~=2) 
        if (k ~= 2) 
            temp1 =temp1*(u^k -(k - 1)^2);
        else 
            temp1 = temp1*((u^2)-(k - 1)^2);
        end
        k=k+1
        d =d*(i-1);
        s = floor((n - i+1) / 2);
        y1 =y1+ (temp1 / (2 * d)) *(delta(s+1,i-1) +delta(s,i - 1));
     else 
        temp2 =temp2* (u^2 -(l - 1)^2)
        l=l+1
        d =d*(i-1)
        s = floor((n - i+1) / 2)
        y1 =y1+ (temp2 / (d)) *delta(s+1,i - 1)
    end
end
disp(y1);
endfunction
x= [0 0.5 1.0 1.5 2.0];
fx=[0 0.191 0.341 0.433 0.477] ;
x1=1.22
n=length(x)
Stirling(x, fx, x1, n);
