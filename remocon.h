const char REMOCON_HTML[] PROGMEM = R"=====(
<!doctype html>
<html class="no-js" lang="">
    <head>
        <meta charset="utf-8">
        <meta http-equiv="x-ua-compatible" content="ie=edge">
        <title>RemoFab MHA-10</title>
        <meta name="description" content="Present for Yuuichi-san">
        <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

        <link rel="stylesheet" href="main.css">
    </head>
    <body>
        <!-- IE9未満への配慮が不要であれば、削除 -->
        <!--[if lte IE 9]>
            <p class="browserupgrade">IE9未満用のメッセージ</p>
        <![endif]-->
        
        <h1>RemoFab MHA-10</h1>

        <!-- ここにサイトやアプリのコンテンツ -->
       
<table border=1><tr><th>No.</th><th>Recieve!</th><th>Go!</th></tr>
    <tr><td>1</td><td><a href="javascript:void(0);" onclick="OnButton(1,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(1,1);">●</a></td></tr>
    <tr><td>2</td><td><a href="javascript:void(0);" onclick="OnButton(2,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(2,1);">●</a></td></tr>
    <tr><td>3</td><td><a href="javascript:void(0);" onclick="OnButton(3,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(3,1);">●</a></td></tr>
    <tr><td>4</td><td><a href="javascript:void(0);" onclick="OnButton(4,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(4,1);">●</a></td></tr>
    <tr><td>5</td><td><a href="javascript:void(0);" onclick="OnButton(5,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(5,1);">●</a></td></tr>
    <tr><td>6</td><td><a href="javascript:void(0);" onclick="OnButton(6,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(6,1);">●</a></td></tr>
    <tr><td>7</td><td><a href="javascript:void(0);" onclick="OnButton(7,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(7,1);">●</a></td></tr>
    <tr><td>8</td><td><a href="javascript:void(0);" onclick="OnButton(8,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(8,1);">●</a></td></tr>
    <tr><td>9</td><td><a href="javascript:void(0);" onclick="OnButton(9,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(9,1);">●</a></td></tr>
    <tr><td>10</td><td><a href="javascript:void(0);" onclick="OnButton(10,2);">●</a></td><td><a href="javascript:void(0);" onclick="OnButton(10,1);">●</a></td></tr>
</table>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<input type="button" value="シモジマ問い合わせ"/>
<input type="button" value="コヤマの家 予約"/>
<input type="button" value="大将ギャグネタ集"/>
<input type="button" value="ムクノキを植える"/>
<input type="button" value="カンジャにエイト"/>
<input type="button" value="ナナナバナナ"/>
        <!-- コンテンツここまで -->
        <script type="text/javascript">
            function OnButton(id, val) {
                var xhr = new XMLHttpRequest();
                xhr.open("GET", `button?id=${id}&val=${val}`);
                xhr.send();
            }
        </script>
            
    </body>
</html>
)=====";
