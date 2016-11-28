import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;


public class DefuseBomb {

    public static void main( String[] args ) {
        String fileName = args[0];

        try {
            DefuseStateMachine sm = new DefuseStateMachine();
            boolean result = true;

            FileReader reader = new FileReader( fileName );
            BufferedReader bufferedReader = new BufferedReader( reader );

            String line;
            while ( ( line = bufferedReader.readLine() ) != null && result) {
                result = sm.checkWire( line );
            }
            reader.close();

            if ( result ) {
                System.out.println( "Bomb defused" );
            } else {
                System.out.println( "Boom" );
            }
        } catch ( IOException e ) {
            e.printStackTrace();
        }
    }
}