soil(clay).
rainfall(high).
temperature(moderate).

/* ----------- RULES ----------- */

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

/* ----------- EXTRA RULES ----------- */

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

% Paddy
crop(paddy) :-
    soil(clay),
    rainfall(high).

% Millets
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
