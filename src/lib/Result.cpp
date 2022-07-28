#pragma once

//
// Created by lexi on 2022-07-27.
//

#include "Result.h"
#include "lib.h"

namespace result {
    template<class T, class E, int CODE = 100>
    class Result {
    public:
        static Result<T, E> Ok(T val) {
            return Result<T, E>(false, val);
        }

        static Result<T, E> Err(E val) {
            return Result<T, E>(false, val);
        }

        bool is_ok() { return !_is_err; }
        bool is_err() { return _is_err; }

        T unwrap() {
            if (!is_err) return ok;
            halt_and_catch_fire("PANIC because STUPID PROGRAMMER\n", CODE);
        }

    private:
        bool _is_err;

        union _u {
            T ok;
            E err;
        };

        _u u;

        Result(bool is_err, _u u) {
            this.u = u;
        }
    };
}
