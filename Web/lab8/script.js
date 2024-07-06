document.addEventListener('DOMContentLoaded', function() {
    // Part 1: Multiple Choice
    const options = document.querySelectorAll('.multiple-choice button');
    const result1 = document.getElementById('result1');

    options.forEach(option => {
        option.addEventListener('click', function() {
            handleMultipleChoiceAnswer(option, result1);
        });
    });

    // Part 2: Free Response
    const submitFreeResponse = document.getElementById('submitFreeResponse');
    const result2 = document.getElementById('result2');

    submitFreeResponse.addEventListener('click', function() {
        handleFreeResponseAnswer(result2);
    });
});

function handleMultipleChoiceAnswer(selectedOption, resultElement) {
    const correctOption = document.querySelector('.multiple-choice button.correct');

    if (selectedOption.textContent.trim() === 'Brasília') {
        showResult(resultElement, true);
        selectedOption.classList.add('correct');
    } else {
        showResult(resultElement, false);
        selectedOption.classList.add('incorrect');
    }

    // Disable all options after answering
    disableMultipleChoiceOptions();
}

function handleFreeResponseAnswer(resultElement) {
    const userAnswer = document.getElementById('freeResponse').value.trim().toLowerCase();

    if (userAnswer === 'mano brown') {
        showResult(resultElement, true);
    } else {
        showResult(resultElement, false);
    }
}

function showResult(resultElement, isCorrect) {
    resultElement.textContent = isCorrect ? 'Correct!' : 'Incorrect';
    resultElement.style.display = 'block';
}

function disableMultipleChoiceOptions() {
    const options = document.querySelectorAll('.multiple-choice button');
    options.forEach(option => {
        option.disabled = true;
    });
}
