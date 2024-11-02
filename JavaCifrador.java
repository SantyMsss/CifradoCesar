package ejemplojni.lib;

public class JavaCifrador {
    // Declaración de métodos nativos
    public native String cifrarCesar(String mensaje, int desplazamiento);
    public native String descifrarCesar(String mensaje, int desplazamiento);
    public native String cifrarEscitala(String mensaje, int numLineas);
    public native String descifrarEscitala(String mensaje, int numLineas);

    static {
        System.loadLibrary("cifrador"); // Carga la biblioteca nativa `libcifrador.so`
    }
}

