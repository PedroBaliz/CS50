-- Keep a log of any SQL queries you execute as you solve the mystery.
SELECT description
FROM crime_scene_reports
WHERE month = 7 AND day = 28 AND street ='Humphrey street';


SELECT *
FROM interviews
WHERE year = 2025 AND month = 7 AND day = 28;


SELECT *
FROM bakery_security_logs
WHERE year = 2025
AND month = 7
AND day = 28
AND activity = 'exit';

SELECT name
FROM people
WHERE license_plate IN (
    SELECT license_plate
    FROM bakery_security_logs
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND activity = 'exit'
);

SELECT name
FROM people
WHERE phone_number IN (
    SELECT caller
    FROM phone_calls
    WHERE year = 2025
    AND month = 7
    AND day = 28
    AND duration < 60
);

SELECT people.name
FROM people
JOIN bank_accounts
ON people.id = bank_accounts.person_id
JOIN atm_transactions
ON bank_accounts.account_number = atm_transactions.account_number
WHERE atm_transactions.year = 2025
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_transactions.transaction_type = 'withdraw';

SELECT *
FROM flights
WHERE year = 2025
AND month = 7
AND day = 29
ORDER BY hour, minute
LIMIT 1;

SELECT name
FROM people
WHERE passport_number IN (
    SELECT passport_number
    FROM passengers
    WHERE flight_id = 36
);

SELECT city
FROM airports
WHERE id = (
    SELECT destination_airport_id
    FROM flights
    WHERE id = 36
);

SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    WHERE caller = (
        SELECT phone_number
        FROM people
        WHERE name = 'Bruce'
    )
    AND duration < 60
);
