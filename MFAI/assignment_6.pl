soil(clay).
rainfall(high).
temperature(moderate).

% Rice
crop(rice) :-
    soil(clay),
    rainfall(high),
    temperature(moderate).

% Wheat
crop(wheat) :-
    rainfall(medium),
    temperature(moderate).

% Cotton
crop(cotton) :-
    soil(black),
    temperature(high).

% Maize
crop(maize) :-
    rainfall(medium).

% Sugarcane
crop(sugarcane) :-
    rainfall(high),
    temperature(high).

% Groundnut
crop(groundnut) :-
    soil(loamy),
    rainfall(medium).

% Barley
crop(barley) :-
    rainfall(low),
    temperature(moderate).

% Paddy (similar to rice)
crop(paddy) :-
    soil(clay),
    rainfall(high).

% Millets (low rainfall + high temp)
crop(millets) :-
    rainfall(low),
    temperature(high).

% Vegetables
crop(vegetables) :-
    soil(loamy),
    rainfall(medium),
    temperature(moderate).

% Pulses
crop(pulses) :-
    rainfall(medium),
    temperature(moderate).

% Jowar
crop(jowar) :-
    rainfall(low),
    temperature(high).

suggest :-
    crop(X),
    write('Recommended Crop: '), write(X), nl,
    fail.

suggest.
