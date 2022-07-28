#pragma once
#define halt_and_catch_fire(code, ...) {\
    fprintf(stderr, __VA_ARGS__);\
    exit(code);\
}

#define nimpl() halt_and_catch_fire(63, "Called something that's not implemented\n")

// side_effect :: IO ()
// #define side_effect() {fprintf(stderr, "scala user detected\n"); execl("bash", "-c", "cope_scala_user(){cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user&};cope_scala_user")}
