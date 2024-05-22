//
// Created by James Daehn on 11/23/19.
//

#include "GradeAccumulator.h"

GradeAccumulator &GradeAccumulator::Instance() {
    static GradeAccumulator instance{0, 0};
    return instance;
}

int GradeAccumulator::GetEarnedPoints() const {
    return earnedPoints_;
}

void GradeAccumulator::IncrementEarnedPointsBy(int points) {
    earnedPoints_ += points;
}

int GradeAccumulator::GetPossiblePoints() const {
    return possiblePoints_;
}

void GradeAccumulator::IncrementPossiblePointsBy(int points) {
    possiblePoints_ += points;
}
