let icon_navlist = document.querySelector('.icons i');
let nav_links = document.querySelector('nav .nav_links');
let main = document.querySelector('main');

icon_navlist.addEventListener('click',()=>{
    nav_links.classList.toggle('hidden');
    main.classList.toggle('margin-nav');
})