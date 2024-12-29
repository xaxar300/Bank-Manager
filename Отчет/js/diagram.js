// Функция для создания стрелок между элементами
function createArrow(fromElement, toElement) {
    const arrow = document.createElement("div");
    arrow.classList.add("diagram-arrow");
    arrow.innerHTML = "↓"; // Стрелка вниз
    toElement.insertAdjacentElement("beforebegin", arrow);
  }
  
  // Функция для создания соединений
  function createConnection(fromElement, toElement) {
    const connector = document.createElement("div");
    connector.classList.add("diagram-connector");
    fromElement.insertAdjacentElement("afterend", connector);
    createArrow(fromElement, toElement);
  }
  
  // Применить соединения для каждого слайда
  document.addEventListener("DOMContentLoaded", function () {
    const bankModule = document.getElementById("bank-module");
    const employeeModule = document.getElementById("employee-module");
    const customerModule = document.getElementById("customer-module");
    const utilsModule = document.getElementById("utils-module");
    const mainModule = document.getElementById("main-module");
  
    // Пример соединений для слайда "bank-module"
    const bankContainer = bankModule.querySelector(".diagram-container");
    const bankBlock = bankContainer.querySelector(".diagram-block");
    const openAccount = bankContainer.querySelector(".diagram-block:nth-child(2)");
    const employee = bankContainer.querySelector(".diagram-block:nth-child(3)");
    const closeAccount = bankContainer.querySelector(".diagram-block:nth-child(4)");
  
    createConnection(bankBlock, openAccount);
    createConnection(openAccount, employee);
    createConnection(employee, closeAccount);
  
    // Повторить аналогичные действия для остальных слайдов
    // ...
  });
  