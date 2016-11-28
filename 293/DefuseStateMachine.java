import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

public class DefuseStateMachine {

    private enum Wire {
        WHITE, BLACK, PURPLE, RED, GREEN, ORANGE
    }

    HashMap<Wire, List<Wire>> acceptedWires;

    private Wire state;

    public DefuseStateMachine() {
        this.state = null;

        this.acceptedWires = new HashMap<Wire, List<Wire>>();
        this.acceptedWires.put(Wire.WHITE, Arrays.asList(
            Wire.PURPLE, Wire.RED, Wire.GREEN, Wire.ORANGE));
        this.acceptedWires.put(Wire.RED, Arrays.asList(
            Wire.GREEN));
        this.acceptedWires.put(Wire.BLACK, Arrays.asList(
            Wire.BLACK, Wire.PURPLE, Wire.RED));
        this.acceptedWires.put(Wire.ORANGE, Arrays.asList(
            Wire.RED, Wire.BLACK));
        this.acceptedWires.put(Wire.GREEN, Arrays.asList(
            Wire.ORANGE, Wire.WHITE));
        this.acceptedWires.put(Wire.PURPLE, Arrays.asList(
            Wire.BLACK, Wire.RED));
    }

    public Wire getCurrentState() {
        return this.state;
    }

    public boolean checkWire( String wire ) {
        return checkWire( getWire( wire ) );
    }

    public boolean checkWire( Wire wire ) {
        if ( wire == null ) {
            return false;
        }

        if ( this.state != null && !acceptedWires.get( this.state ).contains( wire ) ) {
            return false;
        }

        this.state = wire;

        return true;
    }

    private Wire getWire( String wire ) {
        switch ( wire ) {
            case "white": return Wire.WHITE;
            case "black": return Wire.BLACK;
            case "purple": return Wire.PURPLE;
            case "red": return Wire.RED;
            case "green": return Wire.GREEN;
            case "orange": return Wire.ORANGE;
            default: return null;
        }
    }

}