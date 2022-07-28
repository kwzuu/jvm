//
// Created by lexi on 2022-07-27.
//

#ifndef JVM_EITHER_H
#define JVM_EITHER_H

namespace result {
    template<class T, class E>
    class Result {
    public:
        template<class T, class E>
        static Either<T, E> Ok(T val) {
            return Result<T, E>(false, );
        }

        bool is_ok(); // { return !_is_err; }
        bool is_err(); // { return _is_err; }

        T unwrap() {
            if (!is_err) return ok;
            fprintf(stderr, "PANIC because STUPID PROGRAMMER\n");

        }

    private:
        bool _is_err;

        union {
            T ok;
            E err;
        };

        Result(bool is_err, union { T t; E e; });
    };
    template<L, R>
}



#endif //JVM_EITHER_H
