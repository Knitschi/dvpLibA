
#define stringify(x) #x
#define VERSIONED_PATH2(a, b) stringify( a ## / ## b)
#define CPF_VERSIONED_INCLUDE(a, b) VERSIONED_PATH2(a, b)

#define EXPAND(x) x

#define CPF_VERSIONED_NAMESPACE(ns) namespace ns


