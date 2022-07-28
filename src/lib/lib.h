#define halt_and_catch_fire(err, code) {\
    fprintf(stderr, "%s\n", err);\
    exit(code);\
}

#define nimpl() halt_and_catch_fire("Called something that's not implemented\n", 63)

// side_effect :: IO ()
// #define side_effect() {fprintf(stderr, "scala user detected\n"); execl("bash", "-c", "cope_scala_user(){cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user|cope_scala_user&};cope_scala_user")}
