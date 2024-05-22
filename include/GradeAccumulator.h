//
// Created by James Daehn on 11/23/19.
//

#ifndef GRADE_ACCUMULATOR_H
#define GRADE_ACCUMULATOR_H

/**
 * A utility class to gather grade information.
 */
class GradeAccumulator {
public:
    /**
     * Obtain a reference to the single instance of the GradeAccumulator.
     * @return A reference to the single instance of the GradeAccumulator is returned.
     */
    static GradeAccumulator &Instance();

    /**
     * To support the Singleton pattern, we prevent construction using the default constructor.
     */
    GradeAccumulator() = delete;

    /**
     * To support the Singleton pattern, we prevent construction using the copy constructor.
     */
    GradeAccumulator(const GradeAccumulator &) = delete;

    /**
     * To support the Singleton pattern, we prevent construction by the copy assignment operator.
     */
    GradeAccumulator &operator=(const GradeAccumulator &) = delete;

    /**
     * Earned points accessor method.
     * @return The accumulated earned points are returned.
     */
    int GetEarnedPoints() const;

    /**
     * Earned points mutator method.
     * @param points the amount by which to increment the accumulated earned points.
     */
    void IncrementEarnedPointsBy(int points);

    /**
     * Possible points accessor method.
     * @return The accumulated possible points are returned.
     */
    int GetPossiblePoints() const;

    /**
     * Possible points mutator method.
     * @param points the amount by which to incremented the accumulated possible points.
     */
    void IncrementPossiblePointsBy(int points);

private:

    /**
     * To support the Singleton pattern, this private initializing constructor is provided.
     * @param earnedPoints initial earned points, default 0
     * @param possiblePoints initial possible points, default 0
     */
    explicit GradeAccumulator(int earnedPoints = 0, int possiblePoints = 0)
            : earnedPoints_{earnedPoints}, possiblePoints_{possiblePoints} {}

    ~GradeAccumulator() = default;

    int earnedPoints_;
    int possiblePoints_;
};


#endif // GRADE_ACCUMULATOR_H