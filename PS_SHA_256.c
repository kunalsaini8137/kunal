/*********************************************************************
* Filename:   sha256.c
* Author:     Ritesh Aryan
* Disclaimer: This code is presented "as is" without any guarantees.
* Details:    Implementation of the SHA-256 hashing algorithm.
              SHA-256 is one of the three algorithms in the SHA2
              specification. The others, SHA-384 and SHA-512, are not
              offered in this implementation.
              Algorithm specification can be found here:
               * http://csrc.nist.gov/publications/fips/fips180-2/fips180-2withchangenotice.pdf
              This implementation uses little endian uc order.

*********************************************************************/


/************************HEADER FILES*******************/

#include<stdio.h>
#include<memory.h>
#include<string.h>
#include "PS_SHA_256.h"

/******************MACROS USED***********************/

#define ROTLEFT(a,b) (((a) << (b)) | ((a) >> (32-(b))))
#define ROTRIGHT(a,b) (((a) >> (b)) | ((a) << (32-(b))))

#define CH(x,y,z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x,y,z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTRIGHT(x,2) ^ ROTRIGHT(x,13) ^ ROTRIGHT(x,22))
#define EP1(x) (ROTRIGHT(x,6) ^ ROTRIGHT(x,11) ^ ROTRIGHT(x,25))
#define SIG0(x) (ROTRIGHT(x,7) ^ ROTRIGHT(x,18) ^ ((x) >> 3))
#define SIG1(x) (ROTRIGHT(x,17) ^ ROTRIGHT(x,19) ^ ((x) >> 10))





/**************************** VARIABLES *****************************/
static const ui k[64] = {
	0x428a2f98,0x71374491,0xb5c0fbcf,0xe9b5dba5,0x3956c25b,0x59f111f1,0x923f82a4,0xab1c5ed5,
	0xd807aa98,0x12835b01,0x243185be,0x550c7dc3,0x72be5d74,0x80deb1fe,0x9bdc06a7,0xc19bf174,
	0xe49b69c1,0xefbe4786,0x0fc19dc6,0x240ca1cc,0x2de92c6f,0x4a7484aa,0x5cb0a9dc,0x76f988da,
	0x983e5152,0xa831c66d,0xb00327c8,0xbf597fc7,0xc6e00bf3,0xd5a79147,0x06ca6351,0x14292967,
	0x27b70a85,0x2e1b2138,0x4d2c6dfc,0x53380d13,0x650a7354,0x766a0abb,0x81c2c92e,0x92722c85,
	0xa2bfe8a1,0xa81a664b,0xc24b8b70,0xc76c51a3,0xd192e819,0xd6990624,0xf40e3585,0x106aa070,
	0x19a4c116,0x1e376c08,0x2748774c,0x34b0bcb5,0x391c0cb3,0x4ed8aa4a,0x5b9cca4f,0x682e6ff3,
	0x748f82ee,0x78a5636f,0x84c87814,0x8cc70208,0x90befffa,0xa4506ceb,0xbef9a3f7,0xc67178f2
};

/*********************** FUNCTION DEFINITIONS ***********************/

// initialize  initial hash constants

void initilize(SHA2 *ptr)
{
	ptr->datalen = 0;
	ptr->bitlen = 0;
	ptr->state[0] = 0x6a09e667;
	ptr->state[1] = 0xbb67ae85;
	ptr->state[2] = 0x3c6ef372;
	ptr->state[3] = 0xa54ff53a;
	ptr->state[4] = 0x510e527f;
	ptr->state[5] = 0x9b05688c;
	ptr->state[6] = 0x1f83d9ab;
	ptr->state[7] = 0x5be0cd19;
}


// Transforming the data send by the update  function in 64 bit chunks

void transform(SHA2 *ptr, const uc data[])
{
   ui a, b, c, d, e, f, g, h, i, j, t1, t2, m[64];
   for (i = 0, j = 0; i < 16; ++i, j += 4)
		m[i] = (data[j] << 24) | (data[j + 1] << 16) | (data[j + 2] << 8) | (data[j + 3]);
	for ( ; i < 64; ++i)
		m[i] = SIG1(m[i - 2]) + m[i - 7] + SIG0(m[i - 15]) + m[i - 16];

	a = ptr->state[0];
	b = ptr->state[1];
	c = ptr->state[2];
	d = ptr->state[3];
	e = ptr->state[4];
	f = ptr->state[5];
	g = ptr->state[6];
	h = ptr->state[7];

	for (i = 0; i < 64; ++i) {
		t1 = h + EP1(e) + CH(e,f,g) + k[i] + m[i];
		t2 = EP0(a) + MAJ(a,b,c);
		h = g;
		g = f;
		f = e;
		e = d + t1;
		d = c;
		c = b;
		b = a;
		a = t1 + t2;
	}

	ptr->state[0] += a;
	ptr->state[1] += b;
	ptr->state[2] += c;
	ptr->state[3] += d;
	ptr->state[4] += e;
	ptr->state[5] += f;
	ptr->state[6] += g;
	ptr->state[7] += h;



}
//dividind data in to 64 bit chunks

void update(SHA2 *ptr, const uc data[], size_t len)
{
	ui i;

	for (i = 0; i < len; ++i) {
		ptr->data[ptr->datalen] = data[i];
		ptr->datalen++;
		if (ptr->datalen == 64) {
			transform(ptr, ptr->data);
			ptr->bitlen += 512;
			ptr->datalen = 0;
		}
	}
}


void data_final(SHA2 *ptr, uc hash[])
{
    ui i;
    i = ptr->datalen;

	// Pad whatever data is left in the buffer.
	if (ptr->datalen < 56) {
		ptr->data[i++] = 0x80;
		while (i < 56)
			ptr->data[i++] = 0x00;
	}
	else {
		ptr->data[i++] = 0x80;
		while (i < 64)
			ptr->data[i++] = 0x00;
		transform(ptr, ptr->data);
		memset(ptr->data, 0, 56);
	}

	// Append to the padding the total message's length in bits and transform.
	ptr->bitlen += ptr->datalen * 8;
	ptr->data[63] = ptr->bitlen;
	ptr->data[62] = ptr->bitlen >> 8;
	ptr->data[61] = ptr->bitlen >> 16;
	ptr->data[60] = ptr->bitlen >> 24;
	ptr->data[59] = ptr->bitlen >> 32;
	ptr->data[58] = ptr->bitlen >> 40;
	ptr->data[57] = ptr->bitlen >> 48;
	ptr->data[56] = ptr->bitlen >> 56;
	transform(ptr, ptr->data);

	// Since this implementation uses little endian uc ordering and SHA uses big endian,
	// reverse all the ucs when copying the final state to the output hash.

	for (i = 0; i < 4; ++i) {
		hash[i]      = (ptr->state[0] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 4]  = (ptr->state[1] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 8]  = (ptr->state[2] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 12] = (ptr->state[3] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 16] = (ptr->state[4] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 20] = (ptr->state[5] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 24] = (ptr->state[6] >> (24 - i * 8)) & 0x000000ff;
		hash[i + 28] = (ptr->state[7] >> (24 - i * 8)) & 0x000000ff;

		//printf(" %0x", hash[i]);
	}

}

uc* print_hash(uc hash[])
{
    printf("The hash value of your entered string is \n");
   int idx;
   for (idx=0; idx < 32; idx++)
      printf("%02x",hash[idx]);
   printf("\n");

  return  hash;
}

/*int sha256_test()
{
	uc text1[] = {"abc"};
	uc text2[] = {"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"};
	uc text3[] = {"aaaaaaaaaa"};
	uc hash1[SHA256_BLOCK_SIZE] = {0xba,0x78,0x16,0xbf,0x8f,0x01,0xcf,0xea,0x41,0x41,0x40,0xde,0x5d,0xae,0x22,0x23,
	                                 0xb0,0x03,0x61,0xa3,0x96,0x17,0x7a,0x9c,0xb4,0x10,0xff,0x61,0xf2,0x00,0x15,0xad};
	uc hash2[SHA256_BLOCK_SIZE] = {0x24,0x8d,0x6a,0x61,0xd2,0x06,0x38,0xb8,0xe5,0xc0,0x26,0x93,0x0c,0x3e,0x60,0x39,
	                                 0xa3,0x3c,0xe4,0x59,0x64,0xff,0x21,0x67,0xf6,0xec,0xed,0xd4,0x19,0xdb,0x06,0xc1};
	uc hash3[SHA256_BLOCK_SIZE] = {0xcd,0xc7,0x6e,0x5c,0x99,0x14,0xfb,0x92,0x81,0xa1,0xc7,0xe2,0x84,0xd7,0x3e,0x67,
	                                 0xf1,0x80,0x9a,0x48,0xa4,0x97,0x20,0x0e,0x04,0x6d,0x39,0xcc,0xc7,0x11,0x2c,0xd0};
	uc buf[SHA256_BLOCK_SIZE];
	SHA2 ptr;
	int idx;
	int pass = 1;

	initilize(&ptr);
	update(&ptr, text1, strlen(text1));
	data_final(&ptr, buf);
	pass = pass && !memcmp(hash1, buf, SHA256_BLOCK_SIZE);

	initilize(&ptr);
	update(&ptr, text2, strlen(text2));
	data_final(&ptr, buf);
	pass = pass && !memcmp(hash2, buf, SHA256_BLOCK_SIZE);

	initilize(&ptr);
	for (idx = 0; idx < 100000; ++idx)
	   update(&ptr, text3, strlen(text3));
	data_final(&ptr, buf);
	pass = pass && !memcmp(hash3, buf, SHA256_BLOCK_SIZE);



	return(pass);
}

int main()
{
	printf("SHA-256 tests: %s\n", sha256_test() ? "SUCCEEDED" : "FAILED");

	return(0);
} */

/*int main()
{
    uc text1[MAX_LIMIT],hash[32];
    printf("Enter your data yo be hashed \n");
    gets(text1);

   //uc text1[]={"abc"},hash[32];
                 //text2[]={"abcdbcdecdefdefgefghfghighijhijkijkljklmklmnlmnomnopnopq"},
                 //text3[]={"aaaaaaaaaa"},

   int idx;
   SHA2 ptr;

   // Hash one
   initilize(&ptr);
   update(&ptr,text1,strlen(text1));
   data_final(&ptr,hash);
   print_hash(hash);

   // Hash two
   //initilize(&ptr);
   //update(&ptr,text2,strlen(text2));
   //data_final(&ptr,hash);
   //print_hash(hash);

   // Hash three
   //initilize(&ptr);
   //for(idx=0; idx < 100000; ++idx)
       //update(&ptr,text1,strlen(text1));
   //data_final(&ptr,hash);
   //print_hash(hash);

   getchar();
   return 0;
} */



