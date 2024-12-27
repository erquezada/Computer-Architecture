


/*
First Name: Eric
Last Name: Quezada
Student ID: 80532860
Computer Organization Final: Fall 2024
*/
unsigned char alaw_to_ulaw_table[256];
unsigned char ulaw_to_alaw_table[256];
#include <stdio.h>

static inline unsigned char byte_is_zero(unsigned char b) {
  signed short t1, t2, t3;
  unsigned short t4, t5;
  unsigned char t6, t7;

  t1 = (signed short) b;
  t2 = -t1;
  t3 = t2 >> 8;
  t4 = *((unsigned short *) &t3);
  t5 = t4 >> 8;
  t6 = (unsigned char) t5;
  t7 = ~t6;
  return t7;
}

static inline unsigned char byte_top(unsigned char b) {
  unsigned char t, m, o, z, f, s, h, d, k, l;

  t = b;
  
  m = t & ((unsigned char) 0xf0);
  l = byte_is_zero(m);
  k = ~l;
  t = (m & k) | (t & l);
  f = k & ((unsigned char) 0x04);

  m = t & ((unsigned char) 0xcc);
  l = byte_is_zero(m);
  k = ~l;
  t = (m & k) | (t & l);
  z = k & ((unsigned char) 0x02);

  m = t & ((unsigned char) 0xaa);
  l = byte_is_zero(m);
  k = ~l;
  o = k & ((unsigned char) 0x01);

  h = (f | z | o) + ((unsigned char) 1);
  d = byte_is_zero(b);
  s = h & (~d);
  
  return s;
}

signed short alaw_to_slin(unsigned char a) {
  unsigned char t;
  unsigned char h;
  unsigned char l;
  unsigned char s;
  unsigned char e;
  unsigned char k;
  unsigned char q;
  unsigned char y;
  signed short m;
  signed short x;
  signed short z;
  signed short w;
  signed short v;
  signed short r;
  unsigned short u;
  unsigned short g;
  unsigned short f;
  unsigned short j;
  unsigned short d;

  t = a ^ ((unsigned char) 0x55);
  h = t & ((unsigned char) 0x70);
  l = t & ((unsigned char) 0x0f);
  s = t & ((unsigned char) 0x80);
  m = (((signed short) l) << 4) + ((signed short) 0x08);
  e = h >> 4;
  k = byte_is_zero(e);
  q = (~k) & ((unsigned char) 0x01);
  x = (signed short) q;
  z = x << 8;
  w = m + z;
  v = w << (e - q);
  u = *((unsigned short *) &v);
  y = byte_is_zero(s);
  f = (unsigned short) y;
  j = (f << 8) | f;
  d = j & ((unsigned short) 0x01);
  g = (u ^ j) + d;
  r = *((signed short *) &g);
  return r;
}

unsigned char slin_to_alaw(signed short l) {
  unsigned char r;
  unsigned char f;
  unsigned char a;
  unsigned char e;
  unsigned char m;
  unsigned char s;
  unsigned char g;
  unsigned char k;
  unsigned char z;
  unsigned char b;
  unsigned char c;
  unsigned char o;
  unsigned char bh;
  unsigned char bl;
  unsigned char n;
  unsigned char d;
  signed short ll;
  unsigned short w;
  unsigned short v;
  unsigned short t;
  unsigned short p;
  unsigned short q;
  unsigned short y;
  unsigned short wh;
  unsigned short wl;

  ll = l;
  w = *((unsigned short *) &ll);
  wh = w >> 8;
  wl = w & ((unsigned short) 0xff);
  bh = (unsigned char) wh;
  bl = (unsigned char) wl;
  n = (bh ^ ((unsigned char) 0x80)) | bl;
  d = byte_is_zero(n);
  o = d & ((unsigned char) 1);
  y = (unsigned short) o;
  w = w + y;
  z = ((unsigned char) (w >> 8)) & ((unsigned char) 0x80);
  f = (unsigned char) 0x55;
  c = byte_is_zero(z);
  b = ~c;
  q = (unsigned short) b;
  p = (q << 8) | q;
  v = (w ^ p) + (p & ((unsigned short) 1));
  f = f | (z ^ ((unsigned char) 0x80));
  s = (unsigned char) ((v >> 8) & ((unsigned short) 0xff));
  e = byte_top(s);
  k = byte_is_zero(e);
  g = (e & (~k)) | (k & ((unsigned char) 1));
  t = v >> (g + ((unsigned char) 3));
  m = (unsigned char) t;
  a = ((e & ((unsigned char) 0x07)) << 4) | (m & ((unsigned char) 0x0f));
  r = a ^ f;
  return r;
}

signed short ulaw_to_slin(unsigned char u) {
  unsigned char t;
  unsigned char e;
  unsigned char m;
  unsigned char s;
  int v;
  int c;
  int b;
  int g;
  int r;
  signed short res;
  static const int tbl[] = {
    0,
    132,
    396,
    924,
    1980,
    4092,
    8316,
    16764
  };

  if (u == ((unsigned char) 0x7f))
    return (signed short) -1;

  t = ~u;
  s = t & ((unsigned char) 0x80);
  e = (t & ((unsigned char) 0x70)) >> 4;
  m = t & ((unsigned char) 0x0f);
  v = (int) m;
  c = (int) e;
  b = v << (c + 3);
  g = tbl[c] + b;
  if (s != ((unsigned char) 0)) {
    r = -g;
  } else {
    r = g;
  }
  res = (signed short) r;
  return res;
}

unsigned char slin_to_ulaw(signed short l) {
  signed short c;
  signed short a;
  signed short b;
  signed short k;
  unsigned char s;
  unsigned char e;
  unsigned char m;
  unsigned char n;
  unsigned char u;

  static const unsigned char tbl[256] = {
    0, 0, 1, 1, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3,
    4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7,
    7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7
  };

  if (l < ((signed short) -32635)) {
    c = (signed short) -32635;
  } else {
    if (l > ((signed short) 32635)) {
      c = (signed short) -32635;
    } else {
      c = l;
    }
  }
  if (c < ((signed short) 0)) {
    a = -c;
    s = (unsigned char) 0x80;
  } else {
    a = c;
    s = (unsigned char) 0x00;
  }
  b = a + ((signed short) 0x84);
  k = b >> 7;
  e = tbl[k];
  m = ((unsigned char) (b >> (((int) e) + 3))) & ((unsigned char) 0x0f);
  n = s | (e << 4) | m;
  u = ~n;
  return u;
}

unsigned char alaw_to_ulaw(unsigned char a) {
  return slin_to_ulaw(alaw_to_slin(a));
}

unsigned char ulaw_to_alaw(unsigned char u) {
  return slin_to_alaw(ulaw_to_slin(u));
}

unsigned char alaw_to_ulaw_ez(unsigned char a) {
    return alaw_to_ulaw_table[a];
}

// Fast lookup conversion for ulaw to alaw
unsigned char ulaw_to_alaw_ez(unsigned char u) {
    return ulaw_to_alaw_table[u];
}

// Main function that populates the conversion table
int main() {
    unsigned char a, a_to_u, u_to_a;
    a = 0;
    populate_conversion_table:
    if (a >= 255) goto end_loop;
    // Use already implemented functions to get conversions
     a_to_u = alaw_to_ulaw(a);
    u_to_a = ulaw_to_alaw(a);

        // Populate the conversion table using implemented values
    *(alaw_to_ulaw_table + a)  = a_to_u;
    *(ulaw_to_alaw_table + a) = u_to_a;
    // Test for A-law to u-law conversion

    printf("alaw_to_ulaw(%uc) = %uc\n", a, a_to_u);  // Print implemented value
    printf("alaw_to_ulaw_ez(%uc) = %uc\n", a, alaw_to_ulaw_ez(a));  // Print calling ez function

    // Test for u-law to A-law conversion
    printf("ulaw_to_alaw(%uc) = %uc\n", a, u_to_a);  // Print implemented value
    printf("ulaw_to_alaw_ez(%uc) = %uc\n", a, ulaw_to_alaw_ez(a));  // Print calling ez function

    a = a +1;
    goto populate_conversion_table;
    end_loop:
    return 0;
}