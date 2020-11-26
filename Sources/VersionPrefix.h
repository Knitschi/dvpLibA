
#define stringify(x) #x
#define VERSIONED_PATH2(a, b) stringify( a ## / ## b)
#define VERSIONED_PATH(a, b) VERSIONED_PATH2(a, b)
