module lab1_q1(f,x1,x2,x3)
input x1,x2,x3;
output f;
and(g,x1,x2);
and(k,x);
and(h,k,x3);
or(f,g,h);
endmodule
