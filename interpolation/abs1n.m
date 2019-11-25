clear;
k=input('PODAJ MAKSYMALN¥ LICZBÊ WÊZ£ÓW (0 - QUIT) max=');
if (k==0) end
if (k<0) || (k==1) abs1n; end
if (k>1)
for m=2:k
n=m-1;
a=-1;b=1;
step1=(b-a)/n;
x=a:step1:b;
y=abs(5*x);
step2=(b-a)/100;
xt=a:step2:b;
wn=polyfit(x,y,n);
ywn=polyval(wn,xt);
err=abs(ywn-abs(5*xt));
degr(m)=m;
error(m)=max(err);
bar(degr,error);
end
abs1n;
end