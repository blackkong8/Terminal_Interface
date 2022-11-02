#if defined(__clang__)
// flags: -fblocks -lBlocksRuntime
// lBlocksRuntime: apt install libblocksruntime-dev
#define lambda(return_type, function_body) ^return_type function_body
#define lambda_ptr ^
#elif defined(__GNUC__) || defined(__GNUG__)
#define lambda(return_type, function_body) ({ return_type __fn__ function_body __fn__; })
#define lambda_ptr *
#else
#error "[lambda.h] Compiler not supported"
#endif