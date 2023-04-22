module lab1_q2(f,a,b,c,d)
input a,b,c,d;
output f;
assign f=(~a/b)&(c|d);
endmodule
