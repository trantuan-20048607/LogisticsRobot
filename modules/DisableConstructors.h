#ifndef DISABLE_CONSTRUCTORS_H_
#define DISABLE_CONSTRUCTORS_H_

namespace disable_constructors {
    class NoCopy {
    public:
        NoCopy() = default;

        ~NoCopy() = default;

        NoCopy(const NoCopy &) = delete;

        NoCopy &operator=(const NoCopy &) = delete;

        NoCopy(NoCopy &&) = default;

        NoCopy &operator=(NoCopy &&) = default;
    };

    class NoMove {
    public:
        NoMove() = default;

        ~NoMove() = default;

        NoMove(const NoMove &) = default;

        NoMove &operator=(const NoMove &) = default;

        NoMove(NoMove &&) = delete;

        NoMove &operator=(NoMove &&) = delete;
    };
}

#define NO_COPY public disable_constructors::NoCopy

#define NO_MOVE public disable_constructors::NoMove

#endif  // DISABLE_CONSTRUCTORS_H_
