package xyz.teamgravity.jnidemo.presentation.activity

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.enableEdgeToEdge
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.material3.Scaffold
import androidx.compose.ui.Modifier
import xyz.teamgravity.jnidemo.core.extension.log
import xyz.teamgravity.jnidemo.core.sample.ArrayCriticalAccessSample
import xyz.teamgravity.jnidemo.core.sample.OverloadSample
import xyz.teamgravity.jnidemo.core.sample.RegisterNativesSample
import xyz.teamgravity.jnidemo.core.sample.StringCriticalAccessSample
import xyz.teamgravity.jnidemo.core.sample.override.Child
import xyz.teamgravity.jnidemo.core.sample.override.Parent
import xyz.teamgravity.jnidemo.core.util.FileReader
import xyz.teamgravity.jnidemo.core.util.Unsafe
import xyz.teamgravity.jnidemo.core.util.manager.AnimalManager
import xyz.teamgravity.jnidemo.core.util.manager.LoanManager
import xyz.teamgravity.jnidemo.core.util.manager.MathManager
import xyz.teamgravity.jnidemo.core.util.manager.TextManager
import xyz.teamgravity.jnidemo.data.model.AnimalModel
import xyz.teamgravity.jnidemo.data.model.CatModel
import xyz.teamgravity.jnidemo.data.model.DogModel
import xyz.teamgravity.jnidemo.data.model.PeopleModel
import xyz.teamgravity.jnidemo.data.model.PersonModel
import xyz.teamgravity.jnidemo.presentation.theme.JNIDemoTheme
import java.io.File

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()

//        mathManager()
//        loanManager()
//        overloadSample()
//        overrideSample()
        textManager()
//        animalManager()
//        fileReader()
//        person()
//        arrayCriticalAccessSample()
//        stringCriticalAccessSample()
//        unsafe()
//        registerNativesSample()
//        peopleModel()

        setContent {
            JNIDemoTheme {
                Scaffold(
                    modifier = Modifier.fillMaxSize()
                ) { padding ->

                }
            }
        }
    }

    private fun mathManager() {
        MathManager.sayHi()
        val math = MathManager()
        math.multiply(2.0, 2.5).log()
        math.isOdd(10).log()
        math.damage(100).log()
        math.linearSpace(0.0, 5.0, 10).toList().log()
        math.sum(doubleArrayOf(1.0, 5.0, 6.0, 4.0, 5.0)).log()
        math.squareOf(doubleArrayOf(2.0, 7.0, 5.0)).toList().log()
        math.ones(5, 9).contentDeepToString().log()
        math.ones(arrayOf(doubleArrayOf())).contentDeepToString().log()
        math.max(arrayOf(doubleArrayOf(-1.0, 7.0), doubleArrayOf(-4.0, 1.5, -0.5))).log()
        math.callValue({ it * 2 }, 75.0).log()
        math.callValueScaled({ it / 2 }, 90.0).log()
        math.callFunctionScaled { it * 78 }.value(4.0).log()

        MathManager.ai(-1.1).log()
        MathManager.bi(-1.1).log()

        MathManager.rooTestResidual(5.0, 2.0).log()

        MathManager.scale(arrayListOf(4.0, 20.0)).log()
        MathManager.scale(doubleArrayOf(1.0, 100.0)).toList().log()
    }

    private fun loanManager() {
        LoanManager.calculateExtra(100.0).log()
    }

    private fun overloadSample() {
        val sample = OverloadSample()
        sample.add(1.0).log()
        sample.add(1.0, 2.0).log()
        sample.add(1.0, "5.5").log()
        sample.add(1.0, 7.0, 3.0).log()
        sample.minus(5.0).log()
        sample.minus(5.0, 2.7).log()
        sample.multiply(5.2).log()
        sample.multiply(doubleArrayOf(2.3, 5.0, 5.2)).toList().log()
        sample.multiply(2.3, "Ecoboost").log()
        sample.multiply(sample, sample)
        sample.divide_me(5.0)
        sample.divide_me(5)
        sample.hello(5.0)
        OverloadSample.hello(5)
    }

    private fun overrideSample() {
        val parent = Parent()
        parent.mustang().log()
        parent.malibu().log()

        val child = Child()
        child.mustang().log()
        child.malibu().log()
    }

    private fun textManager() {
        TextManager.hello().log()
        TextManager.print("10 000 push-ups.")
        TextManager.concat("Special", " One").log()

        val person = PersonModel("Raheem", 25, true, 777.777)
        TextManager.evaluatePerson(person)
        TextManager.divorcePerson(person)
        person.log()

        TextManager.printPerson(person)
        TextManager.agePeriod(person)

        TextManager.bankrupt(person)
        TextManager.evaluate(person)
        TextManager.freeMemory().log()

        TextManager.createPerson("King Von", -1, true, 0.0).log()
        TextManager.createPerson("Lil Durk").log()

        TextManager.testAnonymousClasses()
    }

    private fun animalManager() {
        val animal = AnimalModel()
        val dog = DogModel()
        val cat = CatModel()

        AnimalManager.speak(animal).log()
        AnimalManager.speak(dog).log()
        AnimalManager.speak(cat).log()

        AnimalManager.animalSpeak(animal).log()
        AnimalManager.animalSpeak(dog).log()
        AnimalManager.animalSpeak(cat).log()

        AnimalManager.dogSpeak(dog).log()

        AnimalManager.catSpeak(cat).log()
    }

    private fun fileReader() {
        val file1 = File(filesDir, "file1.txt")
        file1.createNewFile()
        file1.writeText("Hello, my name is Raheem.")

        FileReader(file1.absolutePath).use { reader ->
            while (!reader.eof()) {
                reader.next().log()
            }
        }

        val file2 = File(filesDir, "file2.txt")
        file2.createNewFile()
        file2.writeText("I drive Ford Mustang GT 5.0")
        FileReader(file2.absolutePath).use { reader ->
            while (!reader.eof()) {
                reader.next().log()
            }
        }
    }

    private fun person() {
        val person = PersonModel("Raheem", 25, true, 0.0)

        val book1 = person.Book("C++")
        book1.printTitle()

        val book2 = person.Book("Kotlin")
        book2.printTitle()

        val bag1 = PersonModel.Bag(21)
        bag1.printSize()
        PersonModel.Bag.printSize(bag1)

        PersonModel.Book.createBook(person).log()
        PersonModel.Bag.createBag().log()

        PersonModel.test()
    }

    private fun arrayCriticalAccessSample() {
        val array = doubleArrayOf(5.0, 2.0, 3.0)
        ArrayCriticalAccessSample.addRegion(array, 7.0)
        array.toList().log()
        ArrayCriticalAccessSample.addElements(array, 15.0)
        array.toList().log()
        ArrayCriticalAccessSample.addCritical(array, 8.0)
        array.toList().log()
    }

    private fun stringCriticalAccessSample() {
        StringCriticalAccessSample.printStringRegular("Hello")
        StringCriticalAccessSample.printStringCritical("My name is Raheem!")
    }

    private fun unsafe() {
        val INT_OFFSET = 4
        val DOUBLE_OFFSET = 8

        val originalAddress = Unsafe.allocateMemory(24)
        var address = originalAddress
        originalAddress.toHexString().log()

        Unsafe.putInt(address, 89719)
        val value1 = Unsafe.getInt(address)
        value1.log()
        address += INT_OFFSET

        Unsafe.putDouble(address, -78.78)
        val value2 = Unsafe.getDouble(address)
        value2.log()
        address += DOUBLE_OFFSET

        Unsafe.putInt(address, 777)
        val value3 = Unsafe.getInt(address)
        value3.log()
        address += INT_OFFSET

        Unsafe.putDouble(address, 89.89)
        val value4 = Unsafe.getDouble(address)
        value4.log()
        address += DOUBLE_OFFSET

        Unsafe.freeMemory(originalAddress)
    }

    private fun registerNativesSample() {
        RegisterNativesSample.doubleValue(78).log()
        RegisterNativesSample().sayHi().log()
    }

    private fun peopleModel() {
        val people = PeopleModel.allocate("Raheem", 21)
        people.sayHi()
        people.name.log()
        people.age.log()
        PeopleModel.free(people)
    }
}