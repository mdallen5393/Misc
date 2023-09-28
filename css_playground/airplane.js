let cursor = document.querySelector("#custom-cursor");
document.addEventListener("mousemove", e => {
    let x = e.clientX;
    let y = e.clientY;
    let angle = Math.atan2(y - window.innerHeight / 2, x - window.innerWidth / 2) * (180 / Math.PI);
    cursor.style.transform = `translate(${x}px, ${y}px) rotate(${angle}deg)`;
});
