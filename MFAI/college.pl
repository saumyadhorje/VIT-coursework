% Students
student(rahul).
student(priya).
student(amit).

% Teachers
teacher(dr_sharma).
teacher(dr_mehta).

% Subjects
subject(ai).
subject(ds).

% Teaching relationships
teaches(dr_sharma, ai).
teaches(dr_mehta, ds).

% Enrollment (student enrolled in subject)
enrolled(rahul, ai).
enrolled(priya, ai).
enrolled(amit, ds).

% Marks (student, subject, marks)
marks(rahul, ai, 85).
marks(priya, ai, 72).
marks(amit, ds, 40).



% Rule 1: Student passes if marks >= 40
pass(Student, Subject) :-
    marks(Student, Subject, Marks),
    Marks >= 40.

% Rule 2: Find teacher of a student
teacher_of_student(Student, Teacher) :-
    enrolled(Student, Subject),
    teaches(Teacher, Subject).

% Rule 3: Eligibility for certificate
% (student passed at least one subject)
eligible(Student) :-
    pass(Student, _).

% -------- Step 3: Universal Quantifier (FOR ALL) ----

% Check if all students enrolled in AI have passed
all_ai_students_passed :-
    forall(
        enrolled(Student, ai),
        pass(Student, ai)
    ).

% -------- Step 4: Existential Quantifier (THERE EXISTS)

% Check if there exists a student with marks > 80
exists_high_scorer(Student) :-
    marks(Student, _, Marks),
    Marks > 80.

% -------- Step 5: Assertions ------------------------

% Add marks dynamically
add_marks(Student, Subject, Marks) :-
    assert(marks(Student, Subject, Marks)).

% -------- Step 6: Equality Checking -----------------

% Check equality and unification
check_marks(Student, Subject, Marks) :-
    marks(Student, Subject, Marks),
    Marks = 85.