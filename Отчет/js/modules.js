document.addEventListener("scroll", () => {
    const moduleSlides = document.querySelectorAll(".module-slide");
    const windowHeight = window.innerHeight;
    const triggerPoint = windowHeight / 1.5;

    moduleSlides.forEach((slide) => {
        const slideTop = slide.getBoundingClientRect().top;

        if (slideTop < triggerPoint && slideTop > -slide.offsetHeight) {
            slide.classList.add("active");
        } else {
            slide.classList.remove("active");
        }
    });
});
