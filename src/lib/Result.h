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

        }

        T unwrap() {

        }

    private:
        bool is_err;

        union {
            T ok;
            E err;
        };

        Result(bool is_err, );
    };
    template<L, R>
}



#endif //JVM_EITHER_H
