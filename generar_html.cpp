#include <fstream>
#include <iostream>

int main() {
    // HTML completo (UTF-8). Usamos un raw string literal para no escapar nada.
    const char* html = R"HTML(
<!DOCTYPE html>
<html lang="es">
<head>
  <meta charset="UTF-8" />
  <meta name="viewport" content="width=device-width, initial-scale=1.0" />
  <title>Feliz Dia de San Valentin Mami</title>

  <!-- ---------- STYLES ---------- -->
  <style>
    body {
      margin: 0;
      padding: 0;
      background: #1b1b1b;
      font-family: "Poppins", sans-serif;
      color: white;
      text-align: center;
      overflow-x: hidden;
    }

    .snow {
      position: fixed;
      top: 0;
      left: 0;
      width: 100%;
      height: 100%;
      pointer-events: none;
      background-image: url("https://i.imgur.com/5xIhEL2.png");
      animation: snow 15s linear infinite;
      opacity: 0.7;
      background-size: contain;
    }
    @keyframes snow {
      0% { background-position: 0px 0px; }
      100% { background-position: 0px 2000px; }
    }

    .container {
      max-width: 800px;
      margin: auto;
      padding: 30px;
    }

    .message {
      font-size: 20px;
      line-height: 1.7;
      margin-bottom: 30px;
      padding: 20px;
      background: rgba(255,255,255,0.1);
      border-radius: 15px;
      box-shadow: 0 0 15px rgba(255,0,0,0.4);
    }

    .photos img {
      width: 90%;
      max-width: 300px;
      border-radius: 20px;
      margin: 15px;
      box-shadow: 0 0 10px rgba(255,255,255,0.5);
    }

    .flower {
      position: fixed;
      bottom: -20px;
      width: 15px;
      height: 15px;
      background: pink;
      border-radius: 50%;
      animation: floatUp 6s linear infinite;
      opacity: 0.8;
    }

    @keyframes floatUp {
      0%   { transform: translateY(0) scale(1); opacity: 1; }
      100% { transform: translateY(-900px) scale(0.5); opacity: 0; }
    }

    .flower:nth-child(1)  { left: 10%; animation-delay: 0s; }
    .flower:nth-child(2)  { left: 20%; animation-delay: 2s; }
    .flower:nth-child(3)  { left: 30%; animation-delay: 4s; }
    .flower:nth-child(4)  { left: 40%; animation-delay: 1s; }
    .flower:nth-child(5)  { left: 50%; animation-delay: 3s; }
    .flower:nth-child(6)  { left: 60%; animation-delay: 5s; }
    .flower:nth-child(7)  { left: 70%; animation-delay: 2.5s; }
    .flower:nth-child(8)  { left: 80%; animation-delay: 4.5s; }
    .flower:nth-child(9)  { left: 90%; animation-delay: 1.5s; }
    .flower:nth-child(10) { left: 15%; animation-delay: 3.5s; }

    #playBtn {
      position: fixed;
      bottom: 20px;
      right: 20px;
      z-index: 9999;
      background: #ff4d4d;
      color: #fff;
      border: none;
      padding: 12px 16px;
      font-size: 16px;
      border-radius: 8px;
      cursor: pointer;
      box-shadow: 0 6px 18px rgba(0,0,0,0.4);
    }
    #playBtn.playing { background: #cc0000; }
    #playBtn:focus { outline: 2px solid #fff; outline-offset: 2px; }

  </style>
</head>

<body>
  <div class="snow"></div>

  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>
  <div class="flower"></div>

  <div class="container">
    <h1 style="font-size: 40px; color: #ff4d4d; text-shadow: 0 0 15px red;">
      ❤️ Happy Valentines Day, Mami ❤️
    </h1>

    <div class="message">
      Feliz Navidad Mami! ❤️  
      Gracias por siempre ser la mejor mamá que Dios pudo darme y por ser ese ejemplo tan claro del amor de Jesús en mi vida.  
      Eres una mujer fuerte, amorosa y llena de bondad, y cada día me doy cuenta de cuánto has sacrificado por mí sin esperar nada a cambio.

      Aprecio cada cosa que haces: tus consejos, tus oraciones, tus palabras que me levantan cuando más lo necesito.  
      Gracias por enseñarme lo que es el amor verdadero, la paciencia y la fe.  
      Le doy gracias a Dios por escogerte como mi mamá.

      Te amo más de lo que puedo decir, mami.  
      Happy Valentines Day ❤️  
      &lt;3
    </div>

     <div class="photos">
  <img src="https://i.imgur.com/RDV76GW.jpg" />
  <img src="https://i.imgur.com/0kgAJh3.jpg" />
  <img src="https://i.imgur.com/HekQ13g.jpg" />
  <img src="https://i.imgur.com/nivKKIg.jpg" />
  <img src="https://i.imgur.com/ljr0IJn.jpg" />
</div>
  </div>

  <audio id="bgAudio" loop preload="auto" playsinline>
    <source src="LastChristmas.mp3" type="audio/mpeg">
    Your browser does not support the audio element.
  </audio>

  <button id="playBtn" aria-pressed="false" aria-label="Play music">▶ Play music</button>

  <script>
    (function() {
      const audio = document.getElementById('bgAudio');
      const btn = document.getElementById('playBtn');

      async function playAudio() {
        try {
          await audio.play();
          btn.textContent = '⏸ Pause music';
          btn.classList.add('playing');
          btn.setAttribute('aria-pressed', 'true');
        } catch (err) {
          console.error('play() failed:', err);
          alert('Playback failed. Please interact with the page and try again.');
        }
      }

      function pauseAudio() {
        audio.pause();
        btn.textContent = '▶ Play music';
        btn.classList.remove('playing');
        btn.setAttribute('aria-pressed', 'false');
      }

      btn.addEventListener('click', async () => {
        if (audio.paused) {
          await playAudio();
        } else {
          pauseAudio();
        }
      });

      audio.addEventListener('pause', () => {
        btn.textContent = '▶ Play music';
        btn.classList.remove('playing');
        btn.setAttribute('aria-pressed', 'false');
      });

      audio.addEventListener('playing', () => {
        btn.textContent = '⏸ Pause music';
        btn.classList.add('playing');
        btn.setAttribute('aria-pressed', 'true');
      });

      document.addEventListener('click', function once() {
        audio.play().catch(()=>{});
        document.removeEventListener('click', once);
      }, { once: true });

    })();
  </script>

</body>
</html>
)HTML";

    // Abrimos archivo en modo binario para preservar UTF-8
    std::ofstream ofs("index.html", std::ios::binary);
    if (!ofs) {
        std::cerr << "Error: no se pudo crear index.html\n";
        return 1;
    }

    ofs << html;
    ofs.close();

    std::cout << "Archivo 'index.html' creado con éxito en el directorio actual.\n";
    std::cout << "Ahora puedes subir ese archivo a tu repositorio de GitHub.\n";
    return 0;
}
