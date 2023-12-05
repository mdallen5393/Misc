<script setup>
import draggable from 'vuedraggable';
import { ref } from 'vue';
import { onClickOutside } from '@vueuse/core';

const isModalOpen = ref(false)
const modal = ref(null)

onClickOutside(modal, () => (isModalOpen.value = false));
</script>

<template>
  <h1 class="text-3xl font-bold underline">
    Vue 3 Modal!
  </h1>
  <button @click="isModalOpen = true">Open Modal</button>
  <Teleport to="#modal">
    <Transition name="modal">
      <div class="modal-bg" v-if="isModalOpen">
        <div class="modal" ref="modal">
          <button @click="isModalOpen = false" class="close-btn">x</button>
          Click outside this modal to close it
        </div>
      </div>
    </Transition>
  </Teleport>
</template>

<style>
.modal-bg {
  /* Always fix modal to the viewport */
  position: fixed;
  top: 0;
  left: 0;
  width: 100vw;
  height: 100vh;

  /* darken the screen */
  background-color: rgba(0, 0, 0, 0.5);

  /* center the modal itself */
  display: flex;
  justify-content: center;
  align-items: center;
}

.modal {
  /* to position button */
  position: relative;

  /* these are all just for aesthetic purposes */
  background: white;
  padding: 50px 100px;
  border-radius: 5px;
  box-shadow: 0px 10px 5px 2px rgba(0, 0, 0, 0.1);
}

.modal .close-btn {
  /* put our modal in the top right */
  position: absolute;
  top: 10px;
  right: 10px;

  /* remove some of the default button styling */
  background: none;
  border: none;
  cursor: pointer;
}

.modal-enter-active,
.modal-leave-active {
  transition: all 0.25s ease;
}

.modal-enter-from,
.modal-leave-to {
  opacity: 0;
  transform: scale(1.1);
}
</style>
