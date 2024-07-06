-- Fetch the duck theft crime scene report
SELECT description
FROM crime_scene_reports
WHERE year = 2020 AND month = 7 AND day = 28 AND street = 'Chamberlin Street';

-- Search for interviews with witnesses to the duck theft
SELECT name, transcript
FROM interviews
WHERE transcript LIKE '%courthouse%' AND year = 2020 AND month = 7 AND day = 28;

-- Search for suspicious transactions at the Fifer Street ATM on the day of the robbery
SELECT account_number
FROM atm_transactions
WHERE year = 2020 AND month = 7 AND day = 28 AND atm_location = 'Fifer Street';

-- Identify the thief from phone calls and bank transactions
SELECT name
FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
JOIN atm_transactions ON bank_accounts.account_number = atm_transactions.account_number
JOIN phone_calls ON people.phone_number = phone_calls.caller
WHERE atm_transactions.year = 2020
    AND atm_transactions.month = 7
    AND atm_transactions.day = 28
    AND phone_calls.year = 2020
    AND phone_calls.month = 7
    AND phone_calls.day = 28
    AND atm_transactions.atm_location = 'Fifer Street';

-- Check if Ernest left the court parking lot on the day of the robbery
SELECT activity, hour, minute
FROM courthouse_security_logs
JOIN people ON courthouse_security_logs.license_plate = people.license_plate
WHERE name = 'Ernest' AND year = 2020 AND month = 7 AND day = 28 AND activity = 'exit';

-- Find out where Ernest flew and who bought the ticket
SELECT city, receiver
FROM airports
JOIN flights ON airports.id = flights.destination_airport_id
JOIN passengers ON flights.id = passengers.flight_id
JOIN people ON passengers.passport_number = people.passport_number
JOIN phone_calls ON people.phone_number = phone_calls.receiver
WHERE people.name = 'Ernest' AND flights.year = 2020 AND flights.month = 7 AND flights.day = 29;

-- Find the name of the accomplice who received Ernest's call
SELECT name
FROM people
WHERE phone_number = (
    SELECT receiver
    FROM phone_calls
    JOIN people ON phone_calls.caller = people.phone_number
    WHERE people.name = 'Ernest' AND year = 2020 AND month = 7 AND day = 28);
