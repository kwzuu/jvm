//
// Created by lexi on 2022-07-27.
//

#ifndef JVM_EITHER_H
#define JVM_EITHER_H

namespace result {
    template<class T, class E>
    class Result {
    public:
        static Result<T, E> Ok(T val);
        static Result<T, E> Err(E val);

        bool is_ok(); // { return !_is_err; }
        bool is_err(); // { return _is_err; }

        T unwrap();
        T expect();

    private:
        union _u {
            T ok;
            E err;
        };

        bool _is_err;

        _u u;

        Result(bool is_err, _u u);
    };
}



#endif //JVM_EITHER_H
