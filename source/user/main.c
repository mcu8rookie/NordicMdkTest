#ifndef __MAIN_C__
#define __MAIN_C__

#include "main.h"

void main_init(void)
{
		test_init();
		return;
}
void main_mainloop(void)
{
		test_mainloop();
		return;
}

int main(void)
{
	main_init();
	
	while(0!=1)
	{
		main_mainloop();
	}
	
	// Occur some if run here.
}

#endif // #ifndef __MAIN_C__




