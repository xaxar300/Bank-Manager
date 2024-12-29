 // Отслеживание текущей позиции прокрутки

 document.addEventListener("scroll", () => {
    const slides = document.querySelectorAll(".slide");
    const windowHeight = window.innerHeight;
    const triggerPoint = windowHeight / 1.5;

    slides.forEach((slide) => {
      const slideTop = slide.getBoundingClientRect().top;

      if (slideTop < triggerPoint && slideTop > -slide.offsetHeight) {
        slide.classList.add("active");
      } else {
        slide.classList.remove("active");
      }
    });
  });

