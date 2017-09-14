#ifdef MAIN_CAN_PRINT
	#include <stdio.h>
	#define PRINT_STRING(x) printf(x)
#else
	#define PRINT_STRING(x) ;
#endif

#ifdef RETURN_TYPE
	#define RETURN RETURN_TYPE
#else
	#define RETURN 
#endif

#ifndef FUNCTION_ARG
	#define FUNCTION_ARG void
	#define USE_ARG
#endif

#ifdef FUNCTION_NAME
	#ifdef FUNCTION_VALUE
		#define USE_ARG FUNCTION_VALUE
	#endif
#endif

#ifndef FUNCTION_NAME
	#define FUNCTION_NAME emptyFunc; 
	#define USE_ARG 
	void emptyFunc() {
		PRINT_STRING("Empty function in main ...");
	}
#else
	RETURN FUNCTION_NAME(USE_ARG);
#endif

int main(int argc, char const *argv[])
{
	#ifdef MAIN_VAR
		MAIN_VAR
	#endif

	#ifdef FUNCTION_NAME
		#ifdef PRINT_RETURN
			#ifdef MAIN_CAN_PRINT
				printf("%d\n", FUNCTION_NAME(USE_ARG));
			#endif
		#else
			FUNCTION_NAME(USE_ARG);
		#endif
	#endif

	return 0;
}