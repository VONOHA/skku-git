#line 179 "bits.c"
int allEvenBits(int x) {
 int result;int fiftyfive=0x55;
 fiftyfive <<=8;
 fiftyfive += 0x55;
 fiftyfive <<=8;
 fiftyfive += 0x55;
 fiftyfive <<= 8;
 fiftyfive += 0x55;
 x = x&fiftyfive;
 result = x^fiftyfive;
 result = !(result);
 return result;
}
#line 200
int allOddBits(int x) {
   int result;int fiftyfive=0x55;
 fiftyfive <<=8;
 fiftyfive += 0x55;
 fiftyfive <<=8;
 fiftyfive += 0x55;
 fiftyfive <<= 8;
 fiftyfive += 0x55;
 fiftyfive = ~fiftyfive;
 x = x&fiftyfive;
 result = x^fiftyfive;
 result = !(result);
 return result;
}
#line 221
int bitAnd(int x, int y) {
  return ~(~x|~y);
}
#line 231
int bitOr(int x, int y) {
  return ~(~x&~y);
}
#line 241
int bitXor(int x, int y) {
   int or=  ~(~x&~y);
 int notor=  ~(x&y);
 return or&notor;
}
#line 253
int isTmax(int x) {
 int _x;int result;int minus1=~0x0;
 _x = x+x+1;
 result = !(_x^minus1);
 result &= !!(x^minus1);
 return result;
}
#line 267
int isTmin(int x) {
 int minus1;int _x;int result;
 x = ~x;
   minus1 = ~0x0;
 _x =x+ 1;
 result = !(~(_x^x));
 result &= !!(x^minus1);
 return result;
}
#line 282
int tmax(void) {
  return ~(1<<31);
}
#line 291
int tmin(void) {
  return 1<<31;
}
#line 301
int negate(int x) {
  return ~x+1;
}
#line 312
int rotateLeft(int x, int n) {
   int num;int result;int reserve=~0x0;
 reserve <<= 32+(~n);
 reserve <<= 1;

 reserve &= x;
 reserve >>= 32+(~n);
 reserve >>= 1;
 num =( ~0x0)<<n;
 num = ~num;
 reserve &= num;
 x <<=n;
 result = reserve + x;
 return result;
}
#line 335
int rotateRight(int x, int n) {
   int result;int num;int reserve=~0x0;
 reserve <<= n;
 reserve = ~reserve;
 reserve &= x;
 reserve <<= 32+(~n);
 reserve <<= 1;
 num =( ~0x0)<<(32+(~n));
 num <<= 1;
 num = ~num;
 x >>= n;
 x &= num;
 result = reserve + x;
 return result;
}
#line 359
int isAsciiDigit(int x) {
   int front;int rear;int msb=(x>>31)&1;
 msb = !msb;
 rear = x & 0xf;
 front =( x>>4);
 front = !(front^0x3);

 rear = rear +( ~10)+1;
 rear >>=31;
 rear &=0x1;
 return msb&front&rear;
}
#line 383
int floatFloat2Int(unsigned uf) {
 int exp=(  0xff)&(uf>>23);int bias=127;int s=(uf>>31)&0x1;int E;
 int f2i=uf;
 f2i &= ~(-1<<23);
 f2i |=( 1<<24);
 E = exp - bias;
 if (E>31) return 0x80000000u;
 if (E<0) return 0x0;
 if (E==0) {
  if (s) return -0x1;
  return 0x1;
 }
 if (E>=23) f2i<<=( E-23);
 else f2i >>=( 23-E);
 if (s) f2i*=-1;
 return f2i;
}
