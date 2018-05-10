#include <stdexcept>

#include "WintroDbg/Exercises/Exercises.h"
#include "WintroDbg/Utils/DebuggingUtils.h"
#include "WintroDbg/Utils/IOUtils.h"
#include "WintroDbg/Utils/TupleUtils.h"

using namespace wintro::exercises;

template <typename ExerciseType>
void runExercise(ExerciseType ex)
{
	wintro::utils::debugBreak();

	while (!ex.check()) {
		displayFailureMessage();
        wintro::utils::debugBreak();
    };
}

template <typename ExerciseType>
void runInputExercise(ExerciseType ex)
{
    wintro::utils::debugBreak();

	decltype(ex.getInput()) input{};
	try {
		input = ex.getInput();
	} catch (const std::exception& ex) {
		printf("%s\n", ex.what());
	}
    while (!ex.checkInput(input)) {
        displayFailureMessage();
        wintro::utils::debugBreak();

        try {
            input = ex.getInput();
        } catch (const std::exception& ex) {
            printf("%s\n", ex.what());
        }
    }
}

int main()
{
    wintro::utils::for_each(getExercises(),
                            [](auto exercise) {
                                displayExercise(exercise);
                                if constexpr (is_input_exercise<decltype(exercise)>) {
                                    runInputExercise(exercise);
                                } else {
                                    runExercise(exercise);
                                }
                            });

    return 0;
}
