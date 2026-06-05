% ----------- FACTS -----------

soil(clay).
rainfall(high).
temperature(moderate).

% ----------- RULES -----------

% Rule 1: Rice
crop(rice) :-
    soil(clay),
    rainfall(high).

% Rule 2: Wheat
crop(wheat) :-
    temperature(moderate),
    rainfall(medium).

% Rule 3: Cotton
crop(cotton) :-
    soil(black),
    temperature(high).

% Rule 4: Maize
crop(maize) :-
    rainfall(moderate).

% ----------- SUGGEST FUNCTION -----------

suggest :-
    crop(X),
    write('Recommended Crop: '), write(X), nl,
    fail.

suggest.