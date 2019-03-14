#include <stdlib.h>
#include <stdio.h>
#include <gmp.h>

int main(int argc,char *argv[]) {
	if(argc != 2) { // make sure we have the right number of arguments
		fprintf(stderr,"usage: %s <number of bits>\n",argv[0]);
		exit(-1);
	}

	mpf_set_default_prec(atoi(argv[1])); // set the number of bits of precision, not that this is NOT number of digits

	mpf_t a0,b,t,p,a1; // the variables

	mpf_init(a0); // init everything
	mpf_init(b);
	mpf_init(t);
	mpf_init(p);
	mpf_init(a1);

	mpf_set_ui(a0,1); // set a0, t, and p to initial values
	mpf_set_d(t,1.0 / 4.0);
	mpf_set_ui(p,1);

	mpf_sqrt_ui(b,2); // set b to 1/sqrt(2)
	mpf_ui_div(b,1,b);

	for(int i = 0; i < 26; i++) { // 26 times should produce many million digits, enough for us
		mpf_add(a1,a0,b); // a1
		mpf_div_ui(a1,a1,2);

		mpf_mul(b,b,a0); // b
		mpf_sqrt(b,b);

		mpf_sub(a0,a0,a1); // t
		mpf_mul(a0,a0,a0);
		mpf_mul(a0,a0,p);
		mpf_sub(t,t,a0);

		mpf_set(a0,a1); // a0

		mpf_mul_ui(p,p,2); // p
	}

	mpf_add(a0,a0,b); // calculate pi
	mpf_mul(a0,a0,a0);
	mpf_mul_ui(t,t,4);
	mpf_div(a0,a0,t);

	mpf_out_str(stdout,10,0,a0); // sadly, it'll print out as 0.<digits>e1, but that's GMP's for you
}
