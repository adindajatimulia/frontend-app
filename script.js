let icon_navlist = document.querySelector('.icons i');
let nav_links = document.querySelector('nav .nav_links');
let main = document.querySelector('main');
let jumboImage = document.querySelector('.jumbo-image');
let coffee1 = document.querySelector('.coffee1');
let coffee2 = document.querySelector('.coffee2');
let coffee3 = document.querySelector('.coffee3');

icon_navlist.addEventListener('click',()=>{
    nav_links.classList.toggle('hidden');
    main.classList.toggle('margin-nav');
})

coffee1.addEventListener('click',()=>{
    jumboImage.src = 'img/coffee 1.png';
    coffee1.src = 'img/coffee 1.png';
    coffee2.src = 'img/coffee 2 bw.png';
    coffee3.src = 'img/coffee 3 bw.png';
})

coffee2.addEventListener('click',()=>{
    jumboImage.src = 'img/coffee 2.png';
    coffee2.src = 'img/coffee 2.png';
    coffee1.src = 'img/coffee 1 bw.png';
    coffee3.src = 'img/coffee 3 bw.png';
})

coffee3.addEventListener('click',()=>{
    jumboImage.src = 'img/coffee 3.png';
    coffee3.src = 'img/coffee 3.png';
    coffee1.src = 'img/coffee 1 bw.png';
    coffee2.src = 'img/coffee 2 bw.png';
})