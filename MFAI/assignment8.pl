% ----------- FACTS (SENSOR DATA) -----------

% Temperature conditions
temperature(high).
temperature(low).

% Time conditions
time(night).

% Motion and presence
motion(detected).
user(home).

% Light condition
light(low).

% Weather
weather(rainy).

% Door status
door(open).

% Smoke detection
smoke(detected).

% Energy saving mode
energy_mode(off).


% ----------- RULES (LOGICAL STATEMENTS) -----------

% Rule 1: AC ON if temperature is high
ac_on :-
    temperature(high).

% Rule 2: Heater ON if temperature is low
heater_on :-
    temperature(low).

% Rule 3: Lights ON if motion detected and low light
lights_on :-
    motion(detected),
    light(low).

% Rule 4: Night security lights ON
security_light :-
    time(night).

% Rule 5: Alarm ON if motion detected and no user at home
alarm_on :-
    motion(detected),
    user(away).

% Rule 6: Close door automatically if raining
close_door :-
    weather(rainy).

% Rule 7: Fire alarm if smoke detected
fire_alarm :-
    smoke(detected).

% Rule 8: Energy saving mode active
energy_saving :-
    energy_mode(on).

% Rule 9: Fan ON if temperature high and user at home
fan_on :-
    temperature(high),
    user(home).