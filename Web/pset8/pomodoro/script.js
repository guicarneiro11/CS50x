let timer;
let isRunning = false;
let timeLeft = 1500;

document.getElementById('startButton').addEventListener('click', () => {
    if (!isRunning) {
        document.body.classList.add('bg-green'); // Muda para verde ao iniciar
        document.body.classList.remove('bg-orange'); // Remove o laranja ao iniciar
        timer = setInterval(() => {
            if (timeLeft > 0) {
                timeLeft--;
                displayTime();
            } else {
                clearInterval(timer);
                alert("Time's up!");
            }
        }, 1000);
        isRunning = true;
    }
});

document.getElementById('resetButton').addEventListener('click', () => {
    clearInterval(timer);
    timeLeft = 1500;
    displayTime();
    isRunning = false;
    document.body.classList.remove('bg-green'); // Remove o verde ao resetar
    document.body.classList.add('bg-orange'); // Volta para laranja ao resetar
});

function displayTime() {
    const minutes = Math.floor(timeLeft / 60);
    const seconds = timeLeft % 60;
    document.getElementById('timer').textContent = `${minutes.toString().padStart(2, '0')}:${seconds.toString().padStart(2, '0')}`;
}

function saveSettings() {
    const workDuration = document.getElementById('workDuration').value;
    const shortBreakDuration = document.getElementById('shortBreakDuration').value;
    const longBreakDuration = document.getElementById('longBreakDuration').value;
    const cycles = document.getElementById('cycles').value;
    const soundNotifications = document.getElementById('soundNotifications').checked;

    localStorage.setItem('workDuration', workDuration);
    localStorage.setItem('shortBreakDuration', shortBreakDuration);
    localStorage.setItem('longBreakDuration', longBreakDuration);
    localStorage.setItem('cycles', cycles);
    localStorage.setItem('soundNotifications', soundNotifications);

    alert('Settings saved!');
}

// Carrega as configurações salvas do localStorage
function loadSettings() {
    const workDuration = parseInt(localStorage.getItem('workDuration')) || 25; // Padrão de 25 minutos
    const shortBreakDuration = parseInt(localStorage.getItem('shortBreakDuration')) || 5; // Padrão de 5 minutos
    const longBreakDuration = parseInt(localStorage.getItem('longBreakDuration')) || 15; // Padrão de 15 minutos
    const cycles = parseInt(localStorage.getItem('cycles')) || 4; // Padrão de 4 ciclos
    const soundNotifications = localStorage.getItem('soundNotifications') === 'true'; // Padrão desativado

    // Atualiza o tempo inicial com a duração do Pomodoro configurada
    timeLeft = workDuration * 60;

    // Exibe o tempo inicial no timer
    displayTime();

    // Salva as configurações carregadas no localStorage (para garantir que estejam atualizadas)
    localStorage.setItem('workDuration', workDuration);
    localStorage.setItem('shortBreakDuration', shortBreakDuration);
    localStorage.setItem('longBreakDuration', longBreakDuration);
    localStorage.setItem('cycles', cycles);
    localStorage.setItem('soundNotifications', soundNotifications);

    return { workDuration, shortBreakDuration, longBreakDuration, cycles, soundNotifications };
}

// Carrega as configurações ao iniciar
window.onload = function() {
    loadSettings();
    displayTime();
}
