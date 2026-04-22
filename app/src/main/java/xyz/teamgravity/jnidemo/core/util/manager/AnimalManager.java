package xyz.teamgravity.jnidemo.core.util.manager;

import xyz.teamgravity.jnidemo.data.model.AnimalModel;
import xyz.teamgravity.jnidemo.data.model.CatModel;
import xyz.teamgravity.jnidemo.data.model.DogModel;

public class AnimalManager {

    static {
        System.loadLibrary("animal_manager");
    }

    public static native String speak(final AnimalModel animal);

    public static native String animalSpeak(final AnimalModel animal);

    public static native String dogSpeak(final DogModel animal);

    public static native String catSpeak(final CatModel animal);
}
